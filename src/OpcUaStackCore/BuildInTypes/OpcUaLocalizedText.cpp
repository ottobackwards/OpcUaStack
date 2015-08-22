#include "OpcUaStackCore/BuildInTypes/OpcUaLocalizedText.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaNumber.h"

namespace OpcUaStackCore
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	// 
	// OpcUaLocalizedText
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	OpcUaLocalizedText::OpcUaLocalizedText(void)
	: ObjectPool<OpcUaLocalizedText>()
	, locale_()
	, text_()
	{
	}

	OpcUaLocalizedText::OpcUaLocalizedText(const std::string& locale, const std::string& text)
	: ObjectPool<OpcUaLocalizedText>()
	, locale_(locale)
	, text_(text)
	{
	}
		
	OpcUaLocalizedText::~OpcUaLocalizedText(void)
	{
	}

	void OpcUaLocalizedText::set(const std::string& locale, const std::string& text)
	{
		locale_ = locale;
		text_ = text;
	}

	void 
	OpcUaLocalizedText::get(std::string& locale, std::string& text)
	{
		locale = locale_;
		text = text_;
	}

	void 
	OpcUaLocalizedText::locale(const OpcUaString& locale)
	{
		locale_ = locale;
	}
		
	void 
	OpcUaLocalizedText::locale(const std::string& locale)
	{
		locale_ = locale;
	}
		
	OpcUaString& 
	OpcUaLocalizedText::locale(void)
	{
		return locale_;
	}
		
	void 
	OpcUaLocalizedText::text(const OpcUaString& text)
	{
		text_ = text;
	}
		
	void 
	OpcUaLocalizedText::text(const std::string& text)
	{
		text_ = text;
	}
	
	OpcUaString& 
	OpcUaLocalizedText::text(void)
	{
		return text_;
	}

	void 
	OpcUaLocalizedText::copyTo(OpcUaLocalizedText& localizedText)
	{
		locale_.copyTo(localizedText.locale());
		text_.copyTo(localizedText.text());
	}

	bool 
	OpcUaLocalizedText::operator!=(const OpcUaLocalizedText& opcUaLocalizedText) const
	{
		return !operator==(opcUaLocalizedText);
	}

	bool 
	OpcUaLocalizedText::operator==(const OpcUaLocalizedText& opcUaLocalizedText) const
	{
		return 
			locale_ == const_cast<OpcUaLocalizedText*>(&opcUaLocalizedText)->locale() && 
			text_ == const_cast<OpcUaLocalizedText*>(&opcUaLocalizedText)->text();
	}

	void 
	OpcUaLocalizedText::out(std::ostream& os) const
	{
		bool outputExist = false;
		if (locale_.exist()) {
			os << "loc=" << locale_;
			outputExist = true;
		}
		if (text_.exist()) {
			if (outputExist == true) os << ",";
			os << "txt=" << text_;
			outputExist = true;
		}

	}

	void 
	OpcUaLocalizedText::opcUaBinaryEncode(std::ostream& os) const
	{
		OpcUaByte encodingMask = 0x00;
		if (locale_.exist()) {
			encodingMask += 0x01;
		}
		if (text_.exist()) {
			encodingMask += 0x02;
		}

		OpcUaNumber::opcUaBinaryEncode(os, encodingMask);
		if (locale_.exist()) {
			locale_.opcUaBinaryEncode(os);
		}
		if (text_.exist()) {
			text_.opcUaBinaryEncode(os);
		}
	}
		
	void 
	OpcUaLocalizedText::opcUaBinaryDecode(std::istream& is)
	{
		OpcUaByte encodingMask;
		OpcUaNumber::opcUaBinaryDecode(is, encodingMask);

		if ((encodingMask & 0x01) == 0x01) {
			locale_.opcUaBinaryDecode(is);
		}
		if ((encodingMask & 0x02) == 0x02) {
			text_.opcUaBinaryDecode(is);
		}
	}

	bool
	OpcUaLocalizedText::encode(boost::property_tree::ptree& pt) const
	{
		if (locale_.exist()) {
			boost::property_tree::ptree locale;
			if (!locale_.encode(locale)) return false;
			pt.add_child("Locale", locale);
		}

		if (text_.exist()) {
			boost::property_tree::ptree text;
			if (!text_.encode(text)) return false;
			pt.add_child("Text", text);
		}

		return true;
	}

	bool
	OpcUaLocalizedText::decode(boost::property_tree::ptree& pt)
	{
		boost::optional<boost::property_tree::ptree&> locale;
		locale = pt.get_child_optional("Locale");
		if (!locale) {
			// do nothing
		}
		else {
			if (!locale_.decode(*locale)) return false;
		}

		boost::optional<boost::property_tree::ptree&> text;
		text = pt.get_child_optional("Text");
		if (!text) {
			// do nothing
		}
		else {
			if (!text_.decode(*text)) return false;
		}
		return true;
	}

};
