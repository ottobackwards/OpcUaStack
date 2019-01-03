/*
    VariableTypeClass: XYArrayItemType

    Generated Source Code - please do not change this source code

    VariableTypeCodeGenerator Version:
        OpcUaStackCore - 4.1.0

    Autor:     Kai Huebl (kai@huebl-sgh.de)
*/

#ifndef __OpcUaStackServer_XYArrayItemType_h__
#define __OpcUaStackServer_XYArrayItemType_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackCore/BuildInTypes/BuildInTypes.h"
#include "OpcUaStackServer/VariableType/VariableBase.h"

namespace OpcUaStackServer
{
   
   class DLLEXPORT XYArrayItemType
   : public VariableBase
   {
     public:
       typedef boost::shared_ptr<XYArrayItemType> SPtr;
       typedef std::vector<XYArrayItemType::SPtr> Vec;
   
       XYArrayItemType(void);
       XYArrayItemType(const XYArrayItemType& value);
       virtual ~XYArrayItemType(void);

        void axisScaleType_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& axisScaleType_Variable(void);
        bool get_AxisScaleType_Variable(OpcUaDataValue& dataValue);
        bool set_AxisScaleType_Variable(const OpcUaDataValue& dataValue);

        void definition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& definition_Variable(void);
        bool get_Definition_Variable(OpcUaDataValue& dataValue);
        bool set_Definition_Variable(const OpcUaDataValue& dataValue);

        void eURange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& eURange_Variable(void);
        bool get_EURange_Variable(OpcUaDataValue& dataValue);
        bool set_EURange_Variable(const OpcUaDataValue& dataValue);

        void engineeringUnits_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& engineeringUnits_Variable(void);
        bool get_EngineeringUnits_Variable(OpcUaDataValue& dataValue);
        bool set_EngineeringUnits_Variable(const OpcUaDataValue& dataValue);

        void instrumentRange_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& instrumentRange_Variable(void);
        bool get_InstrumentRange_Variable(OpcUaDataValue& dataValue);
        bool set_InstrumentRange_Variable(const OpcUaDataValue& dataValue);

        void title_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& title_Variable(void);
        bool get_Title_Variable(OpcUaDataValue& dataValue);
        bool set_Title_Variable(const OpcUaDataValue& dataValue);

        void valuePrecision_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& valuePrecision_Variable(void);
        bool get_ValuePrecision_Variable(OpcUaDataValue& dataValue);
        bool set_ValuePrecision_Variable(const OpcUaDataValue& dataValue);

        void variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& variable(void);
        bool get_Variable(OpcUaDataValue& dataValue);
        bool set_Variable(const OpcUaDataValue& dataValue);

        void xAxisDefinition_Variable(ServerVariable::SPtr& serverVariable);
        ServerVariable::SPtr& xAxisDefinition_Variable(void);
        bool get_XAxisDefinition_Variable(OpcUaDataValue& dataValue);
        bool set_XAxisDefinition_Variable(const OpcUaDataValue& dataValue);
    
      private:
        ServerVariable::SPtr axisScaleType_Variable_;
        ServerVariable::SPtr definition_Variable_;
        ServerVariable::SPtr eURange_Variable_;
        ServerVariable::SPtr engineeringUnits_Variable_;
        ServerVariable::SPtr instrumentRange_Variable_;
        ServerVariable::SPtr title_Variable_;
        ServerVariable::SPtr valuePrecision_Variable_;
        ServerVariable::SPtr variable_;
        ServerVariable::SPtr xAxisDefinition_Variable_;
   
   };

}

#endif
