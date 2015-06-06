#include "unittest.h"

#include "OpcUaStackCore/Base/ConfigXml.h"
#include "OpcUaStackCore/BuildInTypes/OpcUaIdentifier.h"
#include "OpcUaStackServer/AddressSpaceModel/BaseNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/ObjectNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableTypeNodeClass.h"
#include "OpcUaStackServer/AddressSpaceModel/VariableNodeClass.h"
#include "OpcUaStackServer/InformationModel/InformationModelAccess.h"
#include "OpcUaStackServer/InformationModel/InformationModelNodeSet.h"
#include "OpcUaStackServer/NodeSet/NodeSetXmlParser.h"

using namespace OpcUaStackCore;
using namespace OpcUaStackServer;

BOOST_AUTO_TEST_SUITE(Nodeset_)

BOOST_AUTO_TEST_CASE(Nodeset_)
{
	std::cout << "Nodeset_t" << std::endl;
}

BOOST_AUTO_TEST_CASE(Nodeset_MergeNamespace_with_parent_node)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXmlRead1;
	success = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	success = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead1 = InformationModel::construct();
	success = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(success == true);

	informationModelRead1->checkForwardReferences();


	// read raspberry nodeset
	ConfigXml configXmlRead2;
	success = configXmlRead2.read("../tst/data/Opc.Ua.NodeSetRaspberry.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead2;
	success = nodeSetXmlParserRead2.decode(configXmlRead2.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead2 = InformationModel::construct();
	success = InformationModelNodeSet::initial(informationModelRead2, nodeSetXmlParserRead2);
	BOOST_REQUIRE(success == true);

	informationModelRead2->checkForwardReferences();

	// merge namespace 0 and namespace 1
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead1);
	success = informationModelAccess.add(informationModelRead2, 1);
	BOOST_REQUIRE(success == true);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead1, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset-merge.xml");
	BOOST_REQUIRE(success == true);
}

BOOST_AUTO_TEST_CASE(Nodeset_MergeNamespace_without_parent_node)
{
	bool success;

	// read opc ua nodeset
	ConfigXml configXmlRead1;
	success = configXmlRead1.read("../tst/data/Opc.Ua.NodeSet.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead1;
	success = nodeSetXmlParserRead1.decode(configXmlRead1.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead1 = InformationModel::construct();
	success = InformationModelNodeSet::initial(informationModelRead1, nodeSetXmlParserRead1);
	BOOST_REQUIRE(success == true);

	informationModelRead1->checkForwardReferences();


	// read raspberry nodeset
	ConfigXml configXmlRead2;
	success = configXmlRead2.read("../tst/data/Opc.Ua.NodeSetRaspberry1.xml");
	BOOST_REQUIRE(success == true);

	NodeSetXmlParser nodeSetXmlParserRead2;
	success = nodeSetXmlParserRead2.decode(configXmlRead2.ptree());
	BOOST_REQUIRE(success == true);

	InformationModel::SPtr informationModelRead2 = InformationModel::construct();
	success = InformationModelNodeSet::initial(informationModelRead2, nodeSetXmlParserRead2);
	BOOST_REQUIRE(success == true);

	informationModelRead2->checkForwardReferences();

	// merge namespace 0 and namespace 1
	InformationModelAccess informationModelAccess;
	informationModelAccess.informationModel(informationModelRead1);
	success = informationModelAccess.add(informationModelRead2, 1);
	BOOST_REQUIRE(success == true);

	// write nodes from information model into node set file
	NodeSetXmlParser nodeSetXmlParserWrite;
	NamespaceVec namespaceVec;

	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry/");
	namespaceVec.push_back("http://yourorganisation.org/Opc.Ua.Raspberry1/");
	success = InformationModelNodeSet::initial(nodeSetXmlParserWrite, informationModelRead1, namespaceVec);
	BOOST_REQUIRE(success == true);

	ConfigXml configXmlWrite;
	success = nodeSetXmlParserWrite.encode(configXmlWrite.ptree());
	BOOST_REQUIRE(success == true);

	success = configXmlWrite.write("test-nodeset-merge1.xml");
	BOOST_REQUIRE(success == true);
}

BOOST_AUTO_TEST_SUITE_END()


