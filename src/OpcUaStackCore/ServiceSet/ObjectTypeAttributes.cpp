#include "OpcUaStackCore/ServiceSet/ObjectTypeAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// ObjectTypeAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	ObjectTypeAttributes::ObjectTypeAttributes(void)
		: specifiedAttributes_(),
		displayName_(),
		description_(),
		isAbstract_(false),
		writeMask_(),
		userWriteMask_()
	{
		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_IsAbstract;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	ObjectTypeAttributes::~ObjectTypeAttributes(void)
	{
	}

	 OpcUaUInt32
     ObjectTypeAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	ObjectTypeAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	ObjectTypeAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	ObjectTypeAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	ObjectTypeAttributes::description(void) const
	{
		return description_;
	}

	void ObjectTypeAttributes::isAbstract(
		const OpcUaBoolean isAbstract)
	{
		isAbstract_ = isAbstract;
	}

    OpcUaBoolean
	ObjectTypeAttributes::isAbstract(void) const
	{
		return isAbstract_;
	}

	void ObjectTypeAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	ObjectTypeAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void ObjectTypeAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	ObjectTypeAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	ExtensibleParameterBase::BSPtr 
	ObjectTypeAttributes::factory(void)
	{
		return ObjectTypeAttributes::construct();
	}
			
	void 
	ObjectTypeAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, isAbstract_);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	ObjectTypeAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, isAbstract_);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

}