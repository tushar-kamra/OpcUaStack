
/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/lexical_cast.hpp>
#include <sstream>
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaClient/ClientCommand/CommandNodeSet.h"

using namespace OpcUaStackCore;

namespace OpcUaClient
{

	CommandNodeSet::CommandNodeSet(void)
	: CommandBase(CommandBase::Cmd_NodeSet)
	, nodeId_()
	, nodeIdExist_(false)
	{
	}

	CommandNodeSet::~CommandNodeSet(void)
	{
	}

	CommandBase::SPtr
	CommandNodeSet::createCommand(void)
	{
		CommandBase::SPtr commandBase = constructSPtr<CommandNodeSet>();
		return commandBase;
	}

	bool
	CommandNodeSet::validateCommand(void)
	{
		if (!nodeIdExist_) {
			nodeId_.set((OpcUaUInt32)84, (OpcUaUInt16)0);
		}
		return true;
	}

	bool
	CommandNodeSet::addParameter(const std::string& parameterName, const std::string& parameterValue)
	{
		if (parameterName == "-NODEID") {
			if (!nodeId_.fromString(parameterValue)) {
				std::stringstream ss;
				ss << "node id parameter invalid (" << parameterValue << ")";
				errorMessage(ss.str());
				return false;
			}
		}
		else {
			std::stringstream ss;
			ss << "invalid parameter " << parameterName;
			errorMessage(ss.str());
			return false;
		}
		return true;
	}

	std::string
	CommandNodeSet::help(void)
	{
		std::stringstream ss;
		ss << "  -NodeSet: Reads nodes from a opc ua server\n"
		   << "    -Session (0..1): Name of the session.\n"
		   << "    -NodeId (0..1): Start node id\n";
		return ss.str();
	}

	OpcUaNodeId&
	CommandNodeSet::nodeId(void)
	{
		return nodeId_;
	}

}