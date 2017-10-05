/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaStackServer/ServiceSet/ChannelSessionHandleMap.h"

namespace OpcUaStackServer 
{

	ChannelSessionHandleMap::ChannelSessionHandleMap(void)
	: channelIdMap_()
	, sessionIdMap_()
	{
	}

	ChannelSessionHandleMap::~ChannelSessionHandleMap(void)
	{
	}

	ChannelSessionHandle::SPtr
	ChannelSessionHandleMap::createSecureChannel(SecureChannel* secureChannel)
	{
		// create new channel session handle
		ChannelSessionHandle::SPtr channelSessionHandle = constructSPtr<ChannelSessionHandle>();
		channelSessionHandle->secureChannel(secureChannel);

		// added new channel session handle to channel map
		channelIdMap_.insert(std::make_pair(secureChannel->channelId_, channelSessionHandle));

		return channelSessionHandle;
	}

	void
	ChannelSessionHandleMap::deleteSecureChannel(SecureChannel* secureChannel)
	{
		// find secure channel
		ChannelSessionHandle::Map::iterator it;
		it = channelIdMap_.find(secureChannel->channelId_);
		if (it == channelIdMap_.end()) {
			return;
		}
		ChannelSessionHandle::SPtr channelSessionHandle = it->second;
		channelSessionHandle->secureChannel(nullptr);

		// delete element from map
		channelIdMap_.erase(it);
	}

	ChannelSessionHandle::SPtr
	ChannelSessionHandleMap::createSession(Session::SPtr& session, SecureChannel* secureChannel)
	{
		ChannelSessionHandle::SPtr channelSessionHandle;

		// FIXME: the session can be exist...

		// find secure channel
		ChannelSessionHandle::Map::iterator it;
		it = channelIdMap_.find(secureChannel->channelId_);
		if (it == channelIdMap_.end()) {
			return channelSessionHandle;
		}
		channelSessionHandle = it->second;

		// set session and add session to session map
		channelSessionHandle->session(session);
		sessionIdMap_.insert(std::make_pair(session->sessionId(), channelSessionHandle));

		return channelSessionHandle;
	}

	void
	ChannelSessionHandleMap::deleteSession(Session::SPtr& session)
	{
		// find session
		ChannelSessionHandle::Map::iterator it;
		it = sessionIdMap_.find(session->sessionId());
		if (it == sessionIdMap_.end()) {
			return;
		}
		Session::SPtr tmpSession;
		ChannelSessionHandle::SPtr channelSessionHandle = it->second;
		channelSessionHandle->session(tmpSession);

		// delete element from map
		sessionIdMap_.erase(it);
	}

}