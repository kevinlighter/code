
#define BOOST_TEST_MODULE tree_to_list_test
#include <boost/test/included/unit_test.hpp>
#include "tree_to_list.h"

using namespace std;
using namespace common::binary_tree;

BOOST_AUTO_TEST_SUITE(tree_to_list_test)

BOOST_AUTO_TEST_CASE(test_join_func)
{
	Node* node = new_node(3);
	Node* node1 = new_node(5);
	join(node, node1);

	BOOST_REQUIRE(node->val == 3);
	BOOST_REQUIRE(node->right->val == 5);
	BOOST_REQUIRE(node->left == NULL);
	BOOST_REQUIRE(node1->val == 5);
	BOOST_REQUIRE(node1->left->val == 3);
	BOOST_REQUIRE(node1->right == NULL);
}

BOOST_AUTO_TEST_CASE(test_build_linked_list_func)
{
	Node* node = buildDoubleLinkedListThreeValues(1,2,3);
	BOOST_REQUIRE(node->left->val == 3);
	BOOST_REQUIRE(node->left->left->val == 2);
	BOOST_REQUIRE(node->left->left->left->val == 1);
	BOOST_REQUIRE(node->right->val == 2);
	BOOST_REQUIRE(node->right->right->val == 3);
	BOOST_REQUIRE(node->right->right->right->val == 1);
}

BOOST_AUTO_TEST_CASE(test_append_func)
{
	Node* node2 = buildDoubleLinkedListThreeValues(1,2,3);

	Node* node1 = buildDoubleLinkedListThreeValues(4,5,6);

	Node* node = append(node2, node1);

	BOOST_REQUIRE(node->left->val == 6);
	BOOST_REQUIRE(node->left->left->val == 5);
	BOOST_REQUIRE(node->left->left->left->val == 4);
	BOOST_REQUIRE(node->left->left->left->left->val == 3);
	BOOST_REQUIRE(node->left->left->left->left->left->val == 2);
	BOOST_REQUIRE(node->left->left->left->left->left->left->val == 1);
	BOOST_REQUIRE(node->right->val == 2);
	BOOST_REQUIRE(node->right->right->val == 3);
	BOOST_REQUIRE(node->right->right->right->val == 4);
	BOOST_REQUIRE(node->right->right->right->right->val == 5);
	BOOST_REQUIRE(node->right->right->right->right->right->val == 6);
	BOOST_REQUIRE(node->right->right->right->right->right->right->val == 1);

}

BOOST_AUTO_TEST_CASE(test_tree_to_list)
{
	Node* node = NULL;
	
	insert(node, 7);
	insert(node, 3);
	insert(node, 9);
	insert(node, 4);
	insert(node, 2);
	insert(node, 8);
	//print(node);

	Node* list = treeToList(node);

	// printDoubleLinkedList(list);

	BOOST_REQUIRE(list->val == 2);
	BOOST_REQUIRE(list->right->val == 3);
	BOOST_REQUIRE(list->right->right->val == 4);
	BOOST_REQUIRE(list->right->right->right->val == 7);
	BOOST_REQUIRE(list->right->right->right->right->val == 8);
	BOOST_REQUIRE(list->right->right->right->right->right->val == 9);
	BOOST_REQUIRE(list->right->right->right->right->right->right->val == 2);

	BOOST_REQUIRE(list->val == 2);
	BOOST_REQUIRE(list->left->val == 9);
	BOOST_REQUIRE(list->left->left->val == 8);
	BOOST_REQUIRE(list->left->left->left->val == 7);
	BOOST_REQUIRE(list->left->left->left->left->val == 4);
	BOOST_REQUIRE(list->left->left->left->left->left->val ==3);
	BOOST_REQUIRE(list->left->left->left->left->left->left->val == 2);
}

BOOST_AUTO_TEST_SUITE_END()