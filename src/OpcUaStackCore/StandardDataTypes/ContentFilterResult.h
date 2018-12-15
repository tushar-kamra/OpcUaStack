/*
    DataTypeClass: ContentFilterResult

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ContentFilterResult_h__
#define __OpcUaStackCore_ContentFilterResult_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonNumber.h"
#include "OpcUaStackCore/StandardDataTypes/ContentFilterElementResult.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ContentFilterResult
    : public Object
    , public ExtensionObjectBase
    {
      public:
        typedef boost::shared_ptr<ContentFilterResult> SPtr;
        typedef std::vector<ContentFilterResult::SPtr> Vec;
    
        ContentFilterResult(void);
        virtual ~ContentFilterResult(void);
        
        ContentFilterElementResultArray& elementResults(void);
        OpcUaDiagnosticInfoArray& elementDiagnosticInfos(void);
        
        //- ExtensionObjectBase -----------------------------------------------
        virtual ExtensionObjectBase::SPtr factory(void);
        virtual std::string namespaceName(void);
        virtual std::string typeName(void);
        virtual OpcUaNodeId typeId(void);
        virtual OpcUaNodeId binaryTypeId(void);
        virtual OpcUaNodeId xmlTypeId(void);
        virtual OpcUaNodeId jsonTypeId(void);
        virtual void opcUaBinaryEncode(std::ostream& os) const;
        virtual void opcUaBinaryDecode(std::istream& is);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlEncode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, const std::string& element, Xmlns& xmlns);
        virtual bool xmlDecode(boost::property_tree::ptree& pt, Xmlns& xmlns);
        virtual bool jsonEncode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonEncode(boost::property_tree::ptree& pt);
        virtual bool jsonDecode(boost::property_tree::ptree& pt, const std::string& element);
        virtual bool jsonDecode(boost::property_tree::ptree& pt);
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        void copyTo(ContentFilterResult& value);
        bool operator==(const ContentFilterResult& value);
        bool operator!=(const ContentFilterResult& value);
        ContentFilterResult& operator=(const ContentFilterResult& value);
    
      private:
        ContentFilterElementResultArray elementResults_;
        OpcUaDiagnosticInfoArray elementDiagnosticInfos_;
    
    };
    
    class ContentFilterResultArray
    : public OpcUaArray<ContentFilterResult::SPtr, SPtrTypeCoder<ContentFilterResult> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ContentFilterResultArray> SPtr;
    };

}

#endif
