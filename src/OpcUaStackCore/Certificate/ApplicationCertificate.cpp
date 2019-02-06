/*
   Copyright 2018-2019 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   ApplicationCertificatermationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */


#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <iostream>
#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/Certificate/ApplicationCertificate.h"

namespace OpcUaStackCore
{

	ApplicationCertificate::ApplicationCertificate(void)
	: certificate_()
	, privateKey_()
	, enable_(false)
	{
	}

	ApplicationCertificate::~ApplicationCertificate(void)
	{
	}

	bool
	ApplicationCertificate::init(CertificateManager::SPtr& certificateManager)
	{
		CertificateSettings& certificateSettings = certificateManager->certificateSettings();

		Log(Info, "init certificate")
			.parameter("Enable", certificateSettings.enable());

		enable_ = certificateSettings.enable();
		if (!certificateSettings.enable()) {
			// do nothing
			return true;
		}

		// create self signed certificate
		if (!createSelfSignedCertificate(certificateManager)) {
			return false;
		}

		// read own certificate and private key
		if (!readCertificateAndPrivateKey(certificateManager)) {
			return false;
		}

		return true;
	}

	bool
	ApplicationCertificate::cleanup(void)
	{
		certificate_.reset();
		privateKey_.reset();
		return true;
	}

	bool
	ApplicationCertificate::enable(void)
	{
		return enable_;
	}

	Certificate::SPtr&
	ApplicationCertificate::certificate(void)
	{
		return certificate_;
	}

	PrivateKey::SPtr&
	ApplicationCertificate::privateKey(void)
	{
		return privateKey_;
	}

	bool
	ApplicationCertificate::createSelfSignedCertificate(
		CertificateManager::SPtr& certificateManager
	)
	{
		CertificateSettings& certificateSettings = certificateManager->certificateSettings();

		// check if certificate is enabled
		if (!certificateSettings.enable()) {
			return true;
		}

		// check if self signed certificate is enables
		if (!certificateSettings.generateCertificate()) {
			return true;
		}

		// check if private key and certificate exist
		if (certificateManager->existOwnCertificate() && certificateManager->existOwnPrivateKey()) {
			return true;
		}

		// remove certificate file and private key file
		certificateManager->removeOwnCertificate();
		certificateManager->removeOwnPrivateKey();

		// --------------------------------------------------------------------
		// create self signed certificate
		// --------------------------------------------------------------------
		RSAKey key(certificateSettings.keyLength());
		if (key.isError()) {
			key.log(Error, "create RSA key error");
			return false;
		}

		Identity identity;
		identity.organization(certificateSettings.organization());
		identity.organizationUnit(certificateSettings.organizationUnit());
		identity.commonName(certificateSettings.commonName());
		identity.locality(certificateSettings.locality());
		identity.state(certificateSettings.state());
		identity.country(certificateSettings.country());
		identity.domainComponent(certificateSettings.domainComponent());

		CertificateInfo info;
		info.uri(certificateSettings.serverUri());
		info.ipAddresses() = certificateSettings.ipAddress();
		info.dnsNames() = certificateSettings.dnsName();
		info.eMail(certificateSettings.email());
		info.validTime(
			boost::posix_time::microsec_clock::local_time() +
			boost::posix_time::seconds(3600*24*365*certificateSettings.yearsValidFor())
		);
		info.serialNumber(time(0));
		info.validFrom(boost::posix_time::microsec_clock::local_time());

		SignatureAlgorithm signatureAlgorithm;
		if (certificateSettings.certificateType() == "RsaMin") {
			signatureAlgorithm = SignatureAlgorithm_Sha1;
		}
		else {
			signatureAlgorithm = SignatureAlgorithm_Sha256;
		}

		// create self signed certificate
		Certificate certificate(info, identity, key, false, signatureAlgorithm);
		if (certificate.isError()) {
			certificate.log(Error, "create self signed certificate error");
			return false;
		}

		// save self signed cerificate
		if (!certificateManager->writeOwnCertificate(certificate)) {
			return false;
		}

		// save private key
		PrivateKey privateKey = key.privateKey();
		if (!certificateManager->writeOwnPrivateKey(privateKey)) {
			return false;
		}

		return true;
	}

	bool
	ApplicationCertificate::readCertificateAndPrivateKey(CertificateManager::SPtr& certificateManager)
	{
		// read certificate from file
		certificate_ = certificateManager->readOwnCertificate();
		if (certificate_.get() == nullptr) {
			return false;
		}

		// read private key from file
		privateKey_ = certificateManager->readOwnPrivateKey();
		if (privateKey_.get() != nullptr) {
			return false;
		}

		return true;
	}

}
