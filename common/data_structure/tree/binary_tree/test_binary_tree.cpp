
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
	
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	BOOST_REQUIRE(look_up(node, 3) == true);
	BOOST_REQUIRE(look_up(node, 7) == true);
	BOOST_REQUIRE(look_up(node, 9) == true);
	BOOST_REQUIRE(look_up(node, 4) == true);
	BOOST_REQUIRE(look_up(node, 2) == true);
	BOOST_REQUIRE(look_up(node, 8) == true);
	BOOST_REQUIRE(look_up(node, 1) == false);
	//print(node);
}

BOOST_AUTO_TEST_CASE(test_remove_func)
{
	Node* node = NULL;
	
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	remove(node, 7);
	BOOST_REQUIRE(look_up(node, 7) == false);
	BOOST_REQUIRE(node->val == 8);
	BOOST_REQUIRE(node->left->val == 3);
	BOOST_REQUIRE(node->right->val == 9);
	BOOST_REQUIRE(node->left->left->val == 2);
	BOOST_REQUIRE(node->left->right->val == 4);
	//print(node);
}

BOOST_AUTO_TEST_CASE(test_find_func)
{
	Node* node = NULL;
	
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	Node* node1 = find(node, 3);
	BOOST_REQUIRE(node1->val == 3);
	BOOST_REQUIRE(node1->left->val == 2);
	BOOST_REQUIRE(node1->right->val == 4);

	Node* node2 = find(node, 11);
	BOOST_REQUIRE(node2 == NULL);
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
	
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 2);
	//print(node);
	BOOST_REQUIRE(maxDepth(node) == 3);
}

BOOST_AUTO_TEST_CASE(test_min_value_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	BOOST_REQUIRE(minValue(node) == 2);
}

BOOST_AUTO_TEST_CASE(test_max_value_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	BOOST_REQUIRE(maxValue(node) == 9);
}

BOOST_AUTO_TEST_CASE(test_min_node_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	Node* node1 = minNode(node);
	BOOST_REQUIRE(node1->val == 2);
	Node* node2 = minNode(node->right);
	BOOST_REQUIRE(node2->val == 8);
	Node* node3 = NULL;
	BOOST_REQUIRE(minNode(node3) == NULL);
}

BOOST_AUTO_TEST_CASE(test_max_node_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	Node* node1 = maxNode(node);
	BOOST_REQUIRE(node1->val == 9);
	Node* node2 = maxNode(node->left);
	BOOST_REQUIRE(node2->val == 4);
	Node* node3 = NULL;
	BOOST_REQUIRE(maxNode(node3) == NULL);
}

BOOST_AUTO_TEST_CASE(test_print_sorted_order_func){
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	//printSortedOrder(node);
}

BOOST_AUTO_TEST_CASE(test_print_post_order_func){
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	//printPostOrder(node);
}

BOOST_AUTO_TEST_CASE(test_has_path_sum_func){
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

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
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	//printPath(node);
}

BOOST_AUTO_TEST_CASE(test_mirror_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	mirror(node);
	BOOST_REQUIRE(node->val == 7);
	BOOST_REQUIRE(node->left->val == 9);
	BOOST_REQUIRE(node->left->right->val == 8);
	BOOST_REQUIRE(node->right->val == 3);
	BOOST_REQUIRE(node->right->left->val == 4);
	BOOST_REQUIRE(node->right->right->val == 2);
	BOOST_REQUIRE(size(node) == 6);
}

BOOST_AUTO_TEST_CASE(test_double_tree_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	doubleTree(node);
	BOOST_REQUIRE(size(node) == 12);
	BOOST_REQUIRE(node->val == 7);
	BOOST_REQUIRE(node->left->val == 7);
	BOOST_REQUIRE(node->left->left->val == 3);
	BOOST_REQUIRE(node->left->left->left->val == 3);
	BOOST_REQUIRE(node->left->left->left->left->val == 2);
	BOOST_REQUIRE(node->left->left->left->left->left->val == 2);
	BOOST_REQUIRE(node->left->left->right->val == 4);
	BOOST_REQUIRE(node->left->left->right->left->val == 4);
	BOOST_REQUIRE(node->right->val == 9);
	BOOST_REQUIRE(node->right->left->val == 9);
	BOOST_REQUIRE(node->right->left->left->val == 8);
	BOOST_REQUIRE(node->right->left->left->left->val == 8);
}

BOOST_AUTO_TEST_CASE(test_same_tree_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	Node* node1 = NULL;
	insert(node1, 7);
	insert(node1, 3);
	insert(node1, 9);
	insert(node1, 4);
	insert(node1, 2);
	insert(node1, 8);

	BOOST_REQUIRE(sameTree(node, node1) == true);

	insert(node, 18);
	BOOST_REQUIRE(sameTree(node, node1) == false);
}

BOOST_AUTO_TEST_CASE(test_count_tree_func)
{
	BOOST_REQUIRE(countTrees(0) == 1);
	BOOST_REQUIRE(countTrees(1) == 1);
	BOOST_REQUIRE(countTrees(2) == 2);
	BOOST_REQUIRE(countTrees(3) == 5);
	BOOST_REQUIRE(countTrees(4) == 14);
}

BOOST_AUTO_TEST_CASE(test_isBST_func)
{
	Node* node = NULL;
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);

	BOOST_REQUIRE(isBST(node) == true);

	Node* node1 = new_node(11);
	node->left->right->right = node1;
	BOOST_REQUIRE(isBST(node) == false);
}

BOOST_AUTO_TEST_SUITE_END()