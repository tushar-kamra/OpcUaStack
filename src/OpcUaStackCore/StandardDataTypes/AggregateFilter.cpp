/*
    DataTypeClass: AggregateFilter

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor: Kai Huebl (kai@huebl-sgh.de)
*/

#include "OpcUaStackCore/StandardDataTypes/AggregateFilter.h"

namespace OpcUaStackCore
{
    
    AggregateFilter::AggregateFilter(void)
    : MonitoringFilter()
    , startTime_()
    , aggregateType_()
    , processingInterval_()
    , aggregateConfiguration_()
    {
    }
    
    AggregateFilter::~AggregateFilter(void)
    {
    }
    
    OpcUaUtcTime&
    AggregateFilter::startTime(void)
    {
        return startTime_;
    }
    
    OpcUaNodeId&
    AggregateFilter::aggregateType(void)
    {
        return aggregateType_;
    }
    
    OpcUaDuration&
    AggregateFilter::processingInterval(void)
    {
        return processingInterval_;
    }
    
    AggregateConfiguration&
    AggregateFilter::aggregateConfiguration(void)
    {
        return aggregateConfiguration_;
    }
    
    bool
    AggregateFilter::operator==(const AggregateFilter& value)
    {
        AggregateFilter* dst = const_cast<AggregateFilter*>(&value);
        if (startTime_ != dst->startTime()) return false;
        if (aggregateType_ != dst->aggregateType()) return false;
        if (processingInterval_ != dst->processingInterval()) return false;
        if (aggregateConfiguration_ != dst->aggregateConfiguration()) return false;
        return true;
    }
    
    bool
    AggregateFilter::operator!=(const AggregateFilter& value)
    {
        return !this->operator==(value);
    }
    
    void
    AggregateFilter::copyTo(AggregateFilter& value)
    {
        startTime_.copyTo(value.startTime());
        aggregateType_.copyTo(value.aggregateType());
        value.processingInterval_ = processingInterval_;
        aggregateConfiguration_.copyTo(value.aggregateConfiguration());
    }
    
    AggregateFilter&
    AggregateFilter::operator=(const AggregateFilter& value)
    {
        const_cast<AggregateFilter*>(&value)->copyTo(*this);
        return *this;
    }
    
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    //
    // ExtensionObjectBase
    //
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    
    ExtensionObjectBase::SPtr
    AggregateFilter::factory(void)
    {
    	return constructSPtr<AggregateFilter>();
    }
    
    std::string
    AggregateFilter::namespaceName(void)
    {
    	return "http://opcfoundation.org/UA/";
    }
    
    std::string
    AggregateFilter::typeName(void)
    {
    	return "AggregateFilter";
    }
    
    OpcUaNodeId
    AggregateFilter::typeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)728,0);
    }
    
    OpcUaNodeId
    AggregateFilter::binaryTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)730, 0);
    }
    
    OpcUaNodeId
    AggregateFilter::xmlTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)729, 0);
    }
    
    OpcUaNodeId
    AggregateFilter::jsonTypeId(void)
    {
    	return OpcUaNodeId((OpcUaUInt32)15312, 0);
    }
    
    void
    AggregateFilter::opcUaBinaryEncode(std::ostream& os) const
    {
        MonitoringFilter::opcUaBinaryEncode(os);
        startTime_.opcUaBinaryEncode(os);
        aggregateType_.opcUaBinaryEncode(os);
        OpcUaNumber::opcUaBinaryEncode(os,processingInterval_);
        aggregateConfiguration_.opcUaBinaryEncode(os);
    }
    
    void
    AggregateFilter::opcUaBinaryDecode(std::istream& is)
    {
        MonitoringFilter::opcUaBinaryDecode(is);
        startTime_.opcUaBinaryDecode(is);
        aggregateType_.opcUaBinaryDecode(is);
        OpcUaNumber::opcUaBinaryDecode(is,processingInterval_);
        aggregateConfiguration_.opcUaBinaryDecode(is);
    }
    
    bool
    AggregateFilter::encode(boost::property_tree::ptree& pt, Xmlns& xmlns) const
    {
    }
    
    bool
    AggregateFilter::decode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
    }
    
    bool
    AggregateFilter::xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
        if (!xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair(element, elementTree));
        return true;
    }
    
    bool
    AggregateFilter::xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::property_tree::ptree elementTree;
    
        elementTree.clear();
        if (!startTime_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("StartTime", elementTree));
    
        elementTree.clear();
        if (!aggregateType_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AggregateType", elementTree));
    
        elementTree.clear();
        if(!XmlNumber::xmlEncode(elementTree, processingInterval_)) return false;
        pt.push_back(std::make_pair("ProcessingInterval", elementTree));
    
        elementTree.clear();
        if (!aggregateConfiguration_.xmlEncode(elementTree, xmlns)) return false;
        pt.push_back(std::make_pair("AggregateConfiguration", elementTree));
    
        return true;
    }
    
    bool
    AggregateFilter::xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree = pt.get_child_optional(element);
        if (!tree) return false;
        return xmlDecode(*tree, xmlns);
    }
    
    bool
    AggregateFilter::xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns)
    {
        boost::optional<boost::property_tree::ptree&> tree;
    
        tree = pt.get_child_optional("StartTime");
        if (!tree) return false;
        if (!startTime_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("AggregateType");
        if (!tree) return false;
        if (!aggregateType_.xmlDecode(*tree, xmlns)) return false;
    
        tree = pt.get_child_optional("ProcessingInterval");
        if (!tree) return false;
        if(!XmlNumber::xmlDecode(*tree, processingInterval_)) return false;
    
        tree = pt.get_child_optional("AggregateConfiguration");
        if (!tree) return false;
        if (!aggregateConfiguration_.xmlDecode(*tree, xmlns)) return false;
    
        return true;
    }
    
    bool
    AggregateFilter::jsonEncode(boost::property_tree::ptree& pt, const std::string& element)
    {
        return true;
    }
    
    bool
    AggregateFilter::jsonEncode(boost::property_tree::ptree& pt)
    {
        return true;
    }
    
    bool
    AggregateFilter::jsonDecode(boost::property_tree::ptree& pt, const std::string& element)
    {
    }
    
    bool
    AggregateFilter::jsonDecode(boost::property_tree::ptree& pt)
    {
    }
    
    void
    AggregateFilter::copyTo(ExtensionObjectBase& extensionObjectBase)
    {
    	AggregateFilter* dst = dynamic_cast<AggregateFilter*>(&extensionObjectBase);
    	copyTo(*dst);
    }
    
    bool
    AggregateFilter::equal(ExtensionObjectBase& extensionObjectBase) const
    {
    	AggregateFilter* dst = dynamic_cast<AggregateFilter*>(&extensionObjectBase);
    	return *const_cast<AggregateFilter*>(this) == *dst;
    }
    
    void
    AggregateFilter::out(std::ostream& os)
    {
        os << "StartTime="; startTime_.out(os);
        os << ", AggregateType="; aggregateType_.out(os);
        os << ", ProcessingInterval=" << processingInterval_;
        os << ", AggregateConfiguration="; aggregateConfiguration_.out(os);
    }

}
