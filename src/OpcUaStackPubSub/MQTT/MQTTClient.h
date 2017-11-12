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

#ifndef __OpcUaStackPubSub_MQTTClient_h__
#define __OpcUaStackPubSub_MQTTClient_h__

#include <boost/shared_ptr.hpp>
#include "OpcUaStackCore/Base/os.h"
#include "OpcUaStackCore/Base/ObjectPool.h"
#include "OpcUaStackPubSub/MQTT/MQTTClientIf.h"

#ifdef USE_MOSQUITTO_CLIENT
#endif

using namespace OpcUaStackCore;

namespace OpcUaStackPubSub
{

#ifdef USE_MOSQUITTO_CLIENT

	class DLLEXPORT MQTTClient
	: public MQTTClientIf
	{
	  public:
		typedef boost::shared_ptr<MQTTClient> SPtr;

		MQTTClient(void);
		virtual ~MQTTClient(void);

		virtual bool mqttClientIfEnabled(void);
	};

	MQTTClientIf::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClient>();
	}

#else

	MQTTClientIf::SPtr constructMQTT(void)
	{
		return constructSPtr<MQTTClientIf>();
	}

#endif

}

#endif

