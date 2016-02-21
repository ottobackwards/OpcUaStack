
/*
   Copyright 2016 Kai Huebl (kai@huebl-sgh.de)

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

#include "OpcUaClient/Client/ClientApplication.h"
#include "OpcUaClient/ClientCommand/CommandParser.h"
#include "OpcUaClient/ClientService/ClientServiceExecute.h"

// commands
#include "OpcUaClient/ClientCommand/CommandConnect.h"
#include "OpcUaClient/ClientCommand/CommandDisconnect.h"
#include "OpcUaClient/ClientCommand/CommandRead.h"
#include "OpcUaClient/ClientCommand/CommandDelay.h"

// services
#include "OpcUaClient/ClientService/ClientServiceConnect.h"
#include "OpcUaClient/ClientService/ClientServiceDisconnect.h"
#include "OpcUaClient/ClientService/ClientServiceRead.h"
#include "OpcUaClient/ClientService/ClientServiceDelay.h"

namespace OpcUaClient
{

	ClientApplication::ClientApplication(void)
	{
	}

	ClientApplication::~ClientApplication(void)
	{
	}

	int
	ClientApplication::run(uint32_t argc, char** argv)
	{
		// register command in command factory
		CommandParser::addCommand("CONNECT", constructSPtr<CommandConnect>());
		CommandParser::addCommand("DISCONNECT", constructSPtr<CommandDisconnect>());
		CommandParser::addCommand("READ", constructSPtr<CommandRead>());
		CommandParser::addCommand("DELAY", constructSPtr<CommandDelay>());

		// register service in service factory
		ClientServiceExecute::addClientService(CommandBase::Cmd_Connect, constructSPtr<ClientServiceConnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Disconnect, constructSPtr<ClientServiceDisconnect>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Read, constructSPtr<ClientServiceRead>());
		ClientServiceExecute::addClientService(CommandBase::Cmd_Delay, constructSPtr<ClientServiceDelay>());

		// parse command line
		CommandParser commandParser;
		CommandBase::Vec commandBaseVec;
		if (!commandParser.parse(argc, argv, commandBaseVec)) {
			std::cerr << commandParser.errorString() << std::endl;
			return -1;
		}

		// execute commands from command line line
		ClientServiceExecute clientServiceExecute;
		if (!clientServiceExecute.run(commandBaseVec)) {
			std::cerr << clientServiceExecute.errorString() << std::endl;
			return -1;
		}

		std::cout << "OK" << std::endl;
		return 0;
	}

}