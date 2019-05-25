/*
    DataTypeClass: IssuedIdentityToken

    Generated Source Code - please do not change this source code

    DataTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackCore_IssuedIdentityToken_h__
#define __OpcUaStackCore_IssuedIdentityToken_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackCore/BuildInTypes/JsonFormatter.h"
#include "OpcUaStackCore/StandardDataTypes/UserIdentityToken.h"

namespace OpcUaStackCore
{
    
    class DLLEXPORT IssuedIdentityToken
    : public UserIdentityToken
    {
      public:
        typedef boost::shared_ptr<IssuedIdentityToken> SPtr;
        typedef std::vector<IssuedIdentityToken::SPtr> Vec;
    
        IssuedIdentityToken(void);
        IssuedIdentityToken(const IssuedIdentityToken& value);
        virtual ~IssuedIdentityToken(void);
        
        OpcUaByteString& tokenData(void);
        OpcUaString& encryptionAlgorithm(void);
        
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
        
        void copyTo(IssuedIdentityToken& value);
        bool operator==(const IssuedIdentityToken& value);
        bool operator!=(const IssuedIdentityToken& value);
        IssuedIdentityToken& operator=(const IssuedIdentityToken& value);
    
      private:
        OpcUaByteString tokenData_; //!< The XML token encrypted with the server certificate.
        OpcUaString encryptionAlgorithm_; //!< The algorithm used to encrypt the certificate.
    
    };
    
    class IssuedIdentityTokenArray
    : public OpcUaArray<IssuedIdentityToken::SPtr, SPtrTypeCoder<IssuedIdentityToken> >
    , public Object
    {
      public:
    	   typedef boost::shared_ptr<IssuedIdentityTokenArray> SPtr;
    };

}

#endif
