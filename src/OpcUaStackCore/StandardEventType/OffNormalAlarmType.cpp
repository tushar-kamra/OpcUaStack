/*
    EventTypeClass: OffNormalAlarmType

    Generated Source Code - please do not change this source code

    EventTypeCodeGenerator Version:
        OpcUaStackCore - 3.0.1

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardEventType/OffNormalAlarmType.h"

namespace OpcUaStackCore
{
    
    OffNormalAlarmType::OffNormalAlarmType(void)
    : DiscreteAlarmType()
    , eventVariables_()
    {
        eventVariables_.registerEventVariable("NormalState", OpcUaBuildInType_OpcUaNodeId);
    
        eventVariables_.eventType(OpcUaNodeId((OpcUaUInt32)10637));
        eventVariables_.namespaceIndex(0);
        eventVariables_.browseName(OpcUaQualifiedName("OffNormalAlarmType"));
        eventVariables_.namespaceUri("");
    }
    
    OffNormalAlarmType::~OffNormalAlarmType(void)
    {
    }
    
    OpcUaVariant::SPtr 
    OffNormalAlarmType::normalState(void)
    {
    	OpcUaVariant::SPtr value;
    	eventVariables_.getValue("NormalState", value);
    	return value;
    }
    
    bool 
    OffNormalAlarmType::normalState(OpcUaVariant::SPtr& normalState)
    {
    	return eventVariables_.setValue("NormalState", normalState);
    }
    
    void
    OffNormalAlarmType::mapNamespaceUri(void)
    {
        uint32_t namespaceIndex;
        DiscreteAlarmType::mapNamespaceUri();
    
        OpcUaVariant::SPtr eventTypeVariable = constructSPtr<OpcUaVariant>();
        eventTypeVariable->setValue(eventVariables_.eventType());
    
        setNamespaceIndex(eventVariables_.namespaceUri(), namespaceIndex, eventVariables_.browseName(), eventTypeVariable);
    
        eventType(eventTypeVariable);
        eventVariables_.eventType(eventTypeVariable);
        eventVariables_.namespaceIndex(namespaceIndex);
    }

    OpcUaVariant::SPtr
    OffNormalAlarmType::get(
    	OpcUaNodeId& eventType,
    	std::list<OpcUaQualifiedName::SPtr>& browseNameList,
    	EventResult::Code& resultCode
    )
    {
        resultCode = EventResult::Success;

        // check whether eventType and typeNodeId are identical
        if (eventType == eventVariables_.eventType()) {
    	    return eventVariables_.get(browseNameList, resultCode);
        }

        // the start item was not found. We delegate the search to the base class
        OpcUaVariant::SPtr variant;
        variant = DiscreteAlarmType::get(eventType, browseNameList, resultCode);
        if (resultCode != EventResult::Success || browseNameList.empty()) {
    	    return variant;
        }

        return eventVariables_.get(browseNameList, resultCode);
    }

}
