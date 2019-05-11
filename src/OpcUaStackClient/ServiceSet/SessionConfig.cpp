/*
   Copyright 2015-2019 Kai Huebl (kai@huebl-sgh.de)

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

#include <boost/make_shared.hpp>
#include "OpcUaStackClient/ServiceSet/SessionConfig.h"


namespace OpcUaStackClient
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	//  UserAuthentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UserAuthentication::UserAuthentication(UserAuthenticationType userAuthenticationType)
	: userAuthenticationType_(userAuthenticationType)
	, policyId_("anonymous")
	{
	}

	UserAuthentication::~UserAuthentication(void)
	{
	}

	UserAuthenticationType
	UserAuthentication::userAuthenticationType(void)
	{
		return userAuthenticationType_;
	}

	std::string&
	UserAuthentication::policyId(void)
	{
		return policyId_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// AnonymousAuthentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	AnonymousAuthentication::AnonymousAuthentication(const std::string& policyId)
	: UserAuthentication(UserAuthenticationType::Anonymous)
	{
		policyId_ = policyId;
	}

	AnonymousAuthentication::~AnonymousAuthentication(void)
	{
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// UserNameAuthentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	UserNameAuthentication::UserNameAuthentication(
		const std::string& policyId,
		const std::string& userName,
		const std::string& password,
		const std::string& encryptionAlgorithm
	)
	: UserAuthentication(UserAuthenticationType::UserName)
	{
		policyId_ = policyId;
		userName_ = userName;
		password_ = password;
		encryptionAlgorithm_ = encryptionAlgorithm;
	}

	UserNameAuthentication::~UserNameAuthentication(void)
	{
	}

	std::string&
	UserNameAuthentication::userName(void)
	{
		return userName_;
	}

	std::string&
	UserNameAuthentication::password(void)
	{
		return password_;
	}

	std::string&
	UserNameAuthentication::encryptionAlgorithm(void)
	{
		return encryptionAlgorithm_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// X509Authentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	X509Authentication::X509Authentication(
		const std::string& policyId,
		Certificate::SPtr& certificate
	)
	: UserAuthentication(UserAuthenticationType::X509)
	{
		policyId_ = policyId;
		certificate_ = certificate;
	}

	X509Authentication::~X509Authentication(void)
	{
	}

	Certificate::SPtr&
	X509Authentication::certificate(void)
	{
		return certificate_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// IssuedAuthentication
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	IssuedAuthentication::IssuedAuthentication(
		const std::string& policyId,
		const std::string& tokenData,
		const std::string& encryptionAlgorithm
	)
	: UserAuthentication(UserAuthenticationType::Issued)
	{
		policyId_ = policyId;
		tokenData_ = tokenData;
		encryptionAlgorithm_ = encryptionAlgorithm;
	}

	IssuedAuthentication::~IssuedAuthentication(void)
	{
	}

	std::string&
	IssuedAuthentication::tokenData(void)
	{
		return tokenData_;
	}

	std::string&
	IssuedAuthentication::encryptionAlgorithm(void)
	{
		return encryptionAlgorithm_;
	}


	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// SessionConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	SessionConfig::SessionConfig(void)
	: applicationDescription_(constructSPtr<ApplicationDescription>())
	, sessionName_("urn:127.0.0.1:ASNeG.de:ASNeG-Client")
	, sessionTimeout_(3600000)
	, reconnectTimeout_(5000)
	, maxResponseMessageSize_(16777216)
	, requestTimeout_(3000)
	, userAuthentication_(boost::make_shared<AnonymousAuthentication>("anonymous"))
	{
		applicationDescription_->applicationType().enumeration(ApplicationType::EnumClient);
	}

	SessionConfig::~SessionConfig(void)
	{
	}

	void
	SessionConfig::applicationDescription(ApplicationDescription::SPtr& applicationDescription)
	{
		applicationDescription_ = applicationDescription;
	}

	ApplicationDescription::SPtr&
	SessionConfig::applicationDescription(void)
	{
		return applicationDescription_;
	}

	void
	SessionConfig::sessionName(const std::string& sessionName)
	{
		sessionName_ = sessionName;
	}

	std::string&
	SessionConfig::sessionName(void)
	{
		return sessionName_;
	}

	void
	SessionConfig::requestTimeout(uint32_t requestTimeout)
	{
		requestTimeout_ = requestTimeout;
	}

	uint32_t
	SessionConfig::requestTimeout(void)
	{
		return requestTimeout_;
	}

	void
	SessionConfig::sessionTimeout(uint32_t sessionTimeout)
	{
		sessionTimeout_ = sessionTimeout;
	}

	uint32_t
	SessionConfig::sessionTimeout(void)
	{
		return sessionTimeout_;
	}

	void
	SessionConfig::reconnectTimeout(uint32_t reconnectTimeout)
	{
		reconnectTimeout_ = reconnectTimeout;
	}

	uint32_t
	SessionConfig::reconnectTimeout(void)
	{
		return reconnectTimeout_;
	}

	void
	SessionConfig::maxResponseMessageSize(uint32_t maxResponseMessageSize)
	{
		maxResponseMessageSize_ = maxResponseMessageSize;
	}

	uint32_t
	SessionConfig::maxResponseMessageSize(void)
	{
		return maxResponseMessageSize_;
	}

	UserAuthentication::SPtr&
	SessionConfig::userAuthentication(void)
	{
		return userAuthentication_;
	}

	void
	SessionConfig::authenticationAnonymous(
		const std::string& policyId
	)
	{
		userAuthentication_ = boost::make_shared<AnonymousAuthentication>(policyId);
	}

	void
	SessionConfig::authenticationUserName(
		const std::string& policyId,
		const std::string& userName,
		const std::string& password,
		const std::string& encryptionAlgorithm
	)
	{
		userAuthentication_ = boost::make_shared<UserNameAuthentication>(
			policyId,
			userName,
			password,
			encryptionAlgorithm
		);
	}

	void
	SessionConfig::authenticationX509(
		const std::string& policyId,
		Certificate::SPtr& certificate
	)
	{
		userAuthentication_ = boost::make_shared<X509Authentication>(
			policyId,
			certificate
		);
	}

	void
	SessionConfig::authenticationIssued(
		const std::string& policyId,
		const std::string& tokenData,
		const std::string& encryptionAlgorithm
	)
	{
		userAuthentication_ = boost::make_shared<IssuedAuthentication>(
			policyId,
			tokenData,
			encryptionAlgorithm
		);
	}

}
