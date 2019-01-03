
#define BOOST_TEST_MODULE graph_test
#include <boost/test/included/unit_test.hpp>
#include "direct_graph.h"
#include "undirect_graph.h"

using namespace std;
using namespace kevin::graph;

BOOST_AUTO_TEST_SUITE(graph_test)

BOOST_AUTO_TEST_CASE(test_graph_constructor)
{
	BOOST_CHECK_NO_THROW(DirectGraphT<int>(10));
	BOOST_CHECK_NO_THROW(UndirectGraphT<int>(10));
}

BOOST_AUTO_TEST_CASE(test_direct_graph_add_node)
{
	DirectGraphT<int> direct_graph;
	int num = 10;
	for (int i=0;i<num;i++)
	{
		direct_graph.addNode(i);
	}

	BOOST_REQUIRE(direct_graph.size() == 10);
	for (int i=0;i<num;i++)
	{
		BOOST_REQUIRE(direct_graph.nodeExist(i) == true);
	}
	BOOST_REQUIRE(direct_graph.nodeExist(num) == false);
}

