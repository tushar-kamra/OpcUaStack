/*
   Copyright 2015-2020 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaStackServer_ServiceManager_h__
#define __OpcUaStackServer_ServiceManager_h__

#include "OpcUaStackCore/Base/IOService.h"
#include "OpcUaStackServer/InformationModel/InformationModel.h"
#include "OpcUaStackServer/ServiceSet/SessionManager.h"
#include "OpcUaStackServer/ServiceSet/AttributeService.h"
#include "OpcUaStackServer/ServiceSet/MethodService.h"
#include "OpcUaStackServer/ServiceSet/NodeManagementService.h"
#include "OpcUaStackServer/ServiceSet/MonitoredItemService.h"
#include "OpcUaStackServer/ServiceSet/QueryService.h"
#include "OpcUaStackServer/ServiceSet/SubscriptionService.h"
#include "OpcUaStackServer/ServiceSet/ViewService.h"
#include "OpcUaStackServer/ServiceSet/DiscoveryService.h"
#include "OpcUaStackServer/ServiceSetApplication/ApplicationService.h"

namespace OpcUaStackServer
{

	class DLLEXPORT ServiceManager
	{
	  public:
		using SPtr = boost::shared_ptr<ServiceManager>;

		ServiceManager(void);
		~ServiceManager(void);

		bool init(
			SessionManager& sessionManager
		);
		bool informationModel(InformationModel::SPtr informatinModel);
		bool ioThread(OpcUaStackCore::IOThread::SPtr& ioThread);
		bool messageBus(OpcUaStackCore::MessageBus::SPtr& messageBus);
		bool init(void);
		bool shutdown(void);

		ApplicationService::SPtr applicationService(void);
		DiscoveryService::SPtr discoveryService(void);

	  private:
		void initAttributeService(void);
		void initMethodService(void);
		void initNodeManagementService(void);
		void initSubscriptionService(void);
		void initMonitoredItemService(void);
		void initViewService(void);
		void initQueryService(void);
		void initDiscoveryService(void);
		void initForwardGlobalSync(void);

		OpcUaStackCore::IOThread::SPtr ioThread_ = nullptr;
		OpcUaStackCore::MessageBus::SPtr messageBus_ = nullptr;

		OpcUaStackCore::ForwardGlobalSync::SPtr forwardGlobalSync_ = nullptr;

		TransactionManager::SPtr transactionManager_ = nullptr;
		AttributeService::SPtr attributeService_ = nullptr;
		MethodService::SPtr methodService_ = nullptr;
		MonitoredItemService::SPtr monitoredItemService_ = nullptr;
		NodeManagementService::SPtr nodeManagementService_ = nullptr;
		QueryService::SPtr queryService_ = nullptr;
		SubscriptionService::SPtr subscriptionService_ = nullptr;
		ViewService::SPtr viewService_ = nullptr;
		ApplicationService::SPtr applicationService_ = nullptr;
		DiscoveryService::SPtr discoveryService_ = nullptr;
	};

}

#endif
