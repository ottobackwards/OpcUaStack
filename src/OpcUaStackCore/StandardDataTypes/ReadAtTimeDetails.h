/*
    DataTypeClass: ReadAtTimeDetails

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_ReadAtTimeDetails_h__
#define __OpcUaStackCore_ReadAtTimeDetails_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/StandardDataTypes/HistoryReadDetails.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT ReadAtTimeDetails
    : public HistoryReadDetails
    {
      public:
        typedef boost::shared_ptr<ReadAtTimeDetails> SPtr;
        typedef std::vector<ReadAtTimeDetails::SPtr> Vec;
    
        ReadAtTimeDetails(void);
        ReadAtTimeDetails(const ReadAtTimeDetails& value);
        virtual ~ReadAtTimeDetails(void);
        
        OpcUaUtcTimeArray& reqTimes(void);
        OpcUaBoolean& useSimpleBounds(void);
        
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
        virtual void copyTo(ExtensionObjectBase& extensionObjectBase);
        virtual bool equal(ExtensionObjectBase& extensionObjectBase) const;
        virtual void out(std::ostream& os);
        //- ExtensionObjectBase -----------------------------------------------
        
        virtual bool jsonEncodeImpl(boost::property_tree::ptree& pt) const;
        virtual bool jsonDecodeImpl(const boost::property_tree::ptree& pt);
        
        void copyTo(ReadAtTimeDetails& value);
        bool operator==(const ReadAtTimeDetails& value);
        bool operator!=(const ReadAtTimeDetails& value);
        ReadAtTimeDetails& operator=(const ReadAtTimeDetails& value);
    
      private:
        OpcUaUtcTimeArray reqTimes_;
        OpcUaBoolean useSimpleBounds_;
    
    };
    
    class ReadAtTimeDetailsArray
    : public OpcUaArray<ReadAtTimeDetails::SPtr, SPtrTypeCoder<ReadAtTimeDetails> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<ReadAtTimeDetailsArray> SPtr;
    };

}

#endif
