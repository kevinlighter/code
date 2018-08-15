
#define BOOST_TEST_MODULE binary_tree_test
#include <boost/test/included/unit_test.hpp>
#include "binary_tree.h"

using namespace std;
using namespace common::binary_tree;

BOOST_AUTO_TEST_SUITE(binary_tree_test)

BOOST_AUTO_TEST_CASE(test_new_node_func)
{
	Node* node = new_node(3);
	BOOST_REQUIRE(look_up(node, 3) == true);
	BOOST_REQUIRE(look_up(node, 1) == false);
}

BOOST_AUTO_TEST_CASE(test_insert_func)
{
	Node* node = NULL;
	
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	BOOST_REQUIRE(look_up(node, 3) == true);
	BOOST_REQUIRE(look_up(node, 7) == true);
	BOOST_REQUIRE(look_up(node, 9) == true);
	BOOST_REQUIRE(look_up(node, 4) == true);
	BOOST_REQUIRE(look_up(node, 2) == true);
	BOOST_REQUIRE(look_up(node, 8) == true);
	BOOST_REQUIRE(look_up(node, 1) == false);
	//print(node);
}

BOOST_AUTO_TEST_CASE(test_build123)
{
	Node* node = buildOneTwoThree();

	BOOST_REQUIRE(node->val == 2);
	BOOST_REQUIRE(node->left->val == 1);
	BOOST_REQUIRE(node->right->val == 3);
}

BOOST_AUTO_TEST_CASE(test_size_func)
{
	Node* node = buildOneTwoThree();

	BOOST_REQUIRE(size(node) == 3);

	//print(node);
}

BOOST_AUTO_TEST_CASE(test_max_depth_func)
{
	Node* node = NULL;
	
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 2);
	//print(node);
	BOOST_REQUIRE(maxDepth(node) == 3);
}

BOOST_AUTO_TEST_CASE(test_min_value_func)
{
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	BOOST_REQUIRE(minValue(node) == 2);
}

BOOST_AUTO_TEST_CASE(test_max_value_func)
{
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	BOOST_REQUIRE(maxValue(node) == 9);
}

BOOST_AUTO_TEST_CASE(test_print_sorted_order_func){
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	//printSortedOrder(node);
}

BOOST_AUTO_TEST_CASE(test_print_post_order_func){
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	//printPostOrder(node);
}

BOOST_AUTO_TEST_CASE(test_has_path_sum_func){
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	//print(node);
	for (int i=0;i<25;i++) {
		if (i != 12 && i != 14 && i != 16 && i != 24) {
			BOOST_REQUIRE(hasPathSum(node, i) == 0);
		} else {
			BOOST_REQUIRE(hasPathSum(node, i) == 1);
		}
	}
}

BOOST_AUTO_TEST_CASE(test_print_path_func){
	Node* node = NULL;
	node = insert(node, 7);
	node = insert(node, 3);
	node = insert(node, 9);
	node = insert(node, 4);
	node = insert(node, 2);
	node = insert(node, 8);

	printPath(node);
}

BOOST_AUTO_TEST_SUITE_END()