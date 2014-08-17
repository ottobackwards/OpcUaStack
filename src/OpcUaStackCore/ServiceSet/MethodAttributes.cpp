#include "OpcUaStackCore/ServiceSet/MethodAttributes.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// MethodAttributes
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	MethodAttributes::MethodAttributes(void)
		: specifiedAttributes_(),
		displayName_(),
		description_(),
		executable_(false),
		userExecutable_(false),
		writeMask_(),
		userWriteMask_()
	{
		specifiedAttributes_ |= SpecifiedAttributes_Description;
		specifiedAttributes_ |= SpecifiedAttributes_DisplayName;
		specifiedAttributes_ |= SpecifiedAttributes_Executable;
		specifiedAttributes_ |= SpecifiedAttributes_UserExecutable;
		specifiedAttributes_ |= SpecifiedAttributes_WriteMask;
		specifiedAttributes_ |= SpecifiedAttributes_UserWriteMask;
	}

	MethodAttributes::~MethodAttributes(void)
	{
	}

	 OpcUaUInt32
     MethodAttributes::specifiedAttributes(void) const
	 {
		 return specifiedAttributes_;
	 }

	void
	MethodAttributes::displayName(
		const OpcUaLocalizedText::SPtr displayNameSPtr)
	{
		displayName_ = displayNameSPtr;		
	}

    OpcUaLocalizedText::SPtr
	MethodAttributes::displayName(void) const
	{
		return displayName_;
	}

	void
	MethodAttributes::description(
		const OpcUaLocalizedText::SPtr descriptionSPtr)
	{
		description_ = descriptionSPtr;
	}

    OpcUaLocalizedText::SPtr
	MethodAttributes::description(void) const
	{
		return description_;
	}

	void MethodAttributes::executable(
		const OpcUaBoolean executable)
	{
		executable_ = executable;
	}

    OpcUaBoolean
	MethodAttributes::executable(void) const
	{
		return executable_;
	}

	
	void MethodAttributes::userExecutable(
		const OpcUaBoolean userExecutable)
	{
		userExecutable_ = userExecutable;
	}

    OpcUaBoolean
	MethodAttributes::userExecutable(void) const
	{
		return userExecutable_;
	}

	void MethodAttributes::writeMask(
		const WriteableAttribute writeMask)
	{
		writeMask_ |= writeMask;
	}

    OpcUaUInt32
	MethodAttributes::writeMask(void) const
	{
		return writeMask_;
	}

	
	void MethodAttributes::userWriteMask(
		const WriteableAttribute userWriteMask)
	{
		userWriteMask_ |= userWriteMask;
	}

    OpcUaUInt32
	MethodAttributes::userWriteMask(void) const
	{
		return userWriteMask_;
	}

	ExtensibleParameterBase::BSPtr 
	MethodAttributes::factory(void)
	{
		return MethodAttributes::construct();
	}
			
	void 
	MethodAttributes::opcUaBinaryEncode(
		std::ostream& os) const
	{
		OpcUaNumber::opcUaBinaryEncode(os, specifiedAttributes_);
		displayName_->opcUaBinaryEncode(os);
		description_->opcUaBinaryEncode(os);
		OpcUaNumber::opcUaBinaryEncode(os, executable_);
		OpcUaNumber::opcUaBinaryEncode(os, userExecutable_);
		OpcUaNumber::opcUaBinaryEncode(os, writeMask_);
		OpcUaNumber::opcUaBinaryEncode(os, userWriteMask_);
	}
	
	void 
	MethodAttributes::opcUaBinaryDecode(
		std::istream& is)
	{
		OpcUaNumber::opcUaBinaryDecode(is, specifiedAttributes_);
		displayName_->opcUaBinaryDecode(is);
		description_->opcUaBinaryDecode(is);
		OpcUaNumber::opcUaBinaryDecode(is, executable_);
		OpcUaNumber::opcUaBinaryDecode(is, userExecutable_);
		OpcUaNumber::opcUaBinaryDecode(is, writeMask_);
		OpcUaNumber::opcUaBinaryDecode(is, userWriteMask_);
	}

}