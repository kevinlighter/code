
#define BOOST_TEST_MODULE linked_list_test
#include <boost/test/included/unit_test.hpp>
#include "linked_list.h"

using namespace std;
using namespace common::list;

BOOST_AUTO_TEST_SUITE(linked_list_test)

BOOST_AUTO_TEST_CASE(test_create_head)
{
	Node* node = create_dummy(11);
	BOOST_REQUIRE(node->val == 11);
}

BOOST_AUTO_TEST_CASE(test_push_front)
{
	Node* node = NULL;
	Node** ref_head = &node;
	for (int i=5;i>0;i--) {
		push_front(ref_head, i);
	}

	for (int i=1;i<6;i++) {
		BOOST_REQUIRE((*ref_head)->val == i);
		ref_head = &((*ref_head)->next);
	}
	
	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_push_back)
{
	Node* node = NULL;
	Node** ref_head = &node;
	for (int i=1;i<6;i++) {
		push_back(ref_head, i);
	}

	for (int i=1;i<6;i++) {
		BOOST_REQUIRE((*ref_head)->val == i);
		ref_head = &((*ref_head)->next);
	}

	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_push_n)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i, i-1);
	}

	for (int i=1;i<6;i++) {
		BOOST_REQUIRE((*ref_head)->val == i);
		ref_head = &((*ref_head)->next);
	}

	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_count_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	push_front(ref_head, 1);
	push_front(ref_head, 2);
	push_front(ref_head, 1);
	push_front(ref_head, 2);
	push_front(ref_head, 1);
	push_front(ref_head, 3);

	BOOST_REQUIRE(count(ref_head, 1) == 3);
	BOOST_REQUIRE(count(ref_head, 2) == 2);
	BOOST_REQUIRE(count(ref_head, 3) == 1);

	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_val_nth_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i, i-1);
	}

	for (int i=1;i<6;i++) {
		BOOST_REQUIRE(val_nth(ref_head, i-1) == i);
	}

	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_delete_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i, i-1);
	}

	delete_list(ref_head);
	BOOST_REQUIRE(*ref_head == NULL);
}

BOOST_AUTO_TEST_CASE(test_delete_front_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i, i-1);
	}

	delete_front(ref_head);
	BOOST_REQUIRE((*ref_head)->val == 2);
}

BOOST_AUTO_TEST_CASE(test_delete_n_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i, i-1);
	}

	delete_n(ref_head,1);
	BOOST_REQUIRE((*ref_head)->next->val == 3);
}

BOOST_AUTO_TEST_CASE(test_sorted_insert_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_n(ref_head, i*2, i-1);
	} // {2,4,6,8,10}

	Node* insert = NULL;
	push_front(&insert, 7); // {2,4,6,7,8,10}
	sorted_insert(ref_head, insert);
	BOOST_REQUIRE(val_nth(ref_head, 3) == 7);

	free(node);
	ref_head = NULL;
}

BOOST_AUTO_TEST_CASE(test_append_func)
{
	Node* node1 = NULL;
	Node** ref_head1 = &node1;

	for (int i=1;i<6;i++) {
		push_n(ref_head1, i, i-1);
	} // {1,2,3,4,5}

	Node* node2 = NULL;
	Node** ref_head2 = &node2;

	for (int i=6;i<11;i++) {
		push_n(ref_head2, i, i-6);
	} // {6,7,8,9,10}

	append(ref_head1, ref_head2);
	for (int i=1;i<11;i++) {
		BOOST_REQUIRE(val_nth(ref_head1, i-1) == i);
	}

	free(node1);
	free(node2);
	ref_head1 = NULL;
	ref_head2 = NULL;
}

BOOST_AUTO_TEST_CASE(test_insert_sort_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_front(ref_head, i);
	} // {5,4,3,2,1}

	insert_sort(ref_head);
	for (int i=1;i<6;i++) {
		BOOST_REQUIRE(val_nth(ref_head, i-1) == i);
	}
	free(node);
}

BOOST_AUTO_TEST_CASE(test_remove_duplicate_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	push_front(ref_head, 3);
	push_front(ref_head, 2);
	push_front(ref_head, 2);
	push_front(ref_head, 1);
	push_front(ref_head, 1);
	push_front(ref_head, 1);
	// {1,1,1,2,2,3}

	remove_duplicate(ref_head);
	for (int i=0;i<3;i++) {
		BOOST_REQUIRE(val_nth(ref_head, i) == i+1);
	}
	free(node);
}

BOOST_AUTO_TEST_CASE(test_front_back_spilt_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	for (int i=1;i<6;i++) {
		push_front(ref_head, i);
	} // {5,4,3,2,1}

	Node* head1 = NULL;
	Node* head2 = NULL;
	front_back_spilt(ref_head, &head1, &head2);

	BOOST_REQUIRE(val_nth(&head1, 0) == 5);
	BOOST_REQUIRE(val_nth(&head1, 1) == 4);
	BOOST_REQUIRE(val_nth(&head1, 2) == 3);

	BOOST_REQUIRE(val_nth(&head2, 0) == 2);
	BOOST_REQUIRE(val_nth(&head2, 1) == 1);

	free(node);
}

BOOST_AUTO_TEST_CASE(test_move_node_func)
{
	Node* node1 = buildOneTwoThree();
	Node* node2 = buildOneTwoThree();
	move_node(&node1, &node2);

	BOOST_REQUIRE(val_nth(&node1, 0) == 1);
	BOOST_REQUIRE(val_nth(&node1, 1) == 1);
	BOOST_REQUIRE(val_nth(&node1, 2) == 2);
	BOOST_REQUIRE(val_nth(&node1, 3) == 3);

	BOOST_REQUIRE(val_nth(&node2, 0) == 2);
	BOOST_REQUIRE(val_nth(&node2, 1) == 3);

	free(node1);
	free(node2);
}

BOOST_AUTO_TEST_CASE(test_alternating_spilt_func) {
	Node* node = NULL;
	Node** ref_head = &node;

	push_front(ref_head, 1);
	push_front(ref_head, 2);
	push_front(ref_head, 1);
	push_front(ref_head, 2);
	push_front(ref_head, 1);

	Node* node1 = NULL;
	Node* node2 = NULL;

	alternating_spilt(ref_head, &node1, &node2);

	BOOST_REQUIRE(val_nth(&node1, 0) == 1);
	BOOST_REQUIRE(val_nth(&node1, 1) == 1);
	BOOST_REQUIRE(val_nth(&node1, 2) == 1);

	BOOST_REQUIRE(val_nth(&node2, 0) == 2);
	BOOST_REQUIRE(val_nth(&node2, 1) == 2);

	free(node);
	free(node1);
	free(node2);
}
	
BOOST_AUTO_TEST_CASE(test_shuffle_merge_func)
{
	Node* node1 = buildOneTwoThree();
	Node* node2 = NULL;
	Node** ref_head = &node2;

	push_front(ref_head, 4);
	push_front(ref_head, 6);

	Node* result = shuffle_merge(&node1, &node2);

	BOOST_REQUIRE(val_nth(&result, 0) == 1);
	BOOST_REQUIRE(val_nth(&result, 1) == 6);
	BOOST_REQUIRE(val_nth(&result, 2) == 2);
	BOOST_REQUIRE(val_nth(&result, 3) == 4);
	BOOST_REQUIRE(val_nth(&result, 4) == 3);

	free(node1);
	free(node2);
	free(result);
}

BOOST_AUTO_TEST_CASE(test_sorted_merge_func)
{
	Node* node1 = NULL;
	Node* node2 = NULL;
	Node** ref_head1 = &node1;
	Node** ref_head2 = &node2;

	push_front(ref_head1, 5);
	push_front(ref_head1, 3);

	push_front(ref_head2, 8);
	push_front(ref_head2, 4);
	push_front(ref_head2, 2);


	Node* result = sorted_merge(ref_head1, ref_head2);

	BOOST_REQUIRE(val_nth(&result, 0) == 2);
	BOOST_REQUIRE(val_nth(&result, 1) == 3);
	BOOST_REQUIRE(val_nth(&result, 2) == 4);
	BOOST_REQUIRE(val_nth(&result, 3) == 5);
	BOOST_REQUIRE(val_nth(&result, 4) == 8);

	free(node1);
	free(node2);
	free(result);
}

BOOST_AUTO_TEST_CASE(test_merge_sort_func)
{
	Node* node = NULL;
	Node** ref_head = &node;

	push_front(ref_head, 5);
	push_front(ref_head, 4);
	push_front(ref_head, 52);
	push_front(ref_head, 51);
	push_front(ref_head, 15);

	merge_sort(ref_head);

	BOOST_REQUIRE(val_nth(ref_head, 0) == 4);
	BOOST_REQUIRE(val_nth(ref_head, 1) == 5);
	BOOST_REQUIRE(val_nth(ref_head, 2) == 15);
	BOOST_REQUIRE(val_nth(ref_head, 3) == 51);
	BOOST_REQUIRE(val_nth(ref_head, 4) == 52);

	free(node);
}

BOOST_AUTO_TEST_CASE(test_sort_intersect_func)
{
	Node* node1 = buildOneTwoThree();
	Node* node2 = buildOneTwoThree();

	Node* result = sorted_intersect(&node1, &node2);

	BOOST_REQUIRE(val_nth(&node1, 0) == 1);
	BOOST_REQUIRE(val_nth(&node1, 1) == 2);
	BOOST_REQUIRE(val_nth(&node1, 2) == 3);

	BOOST_REQUIRE(val_nth(&node2, 0) == 1);
	BOOST_REQUIRE(val_nth(&node2, 1) == 2);
	BOOST_REQUIRE(val_nth(&node2, 2) == 3);

	BOOST_REQUIRE(val_nth(&result, 0) == 3);
	BOOST_REQUIRE(val_nth(&result, 1) == 2);
	BOOST_REQUIRE(val_nth(&result, 2) == 1);

	free(node1);
	free(node2);
	free(result);
}

BOOST_AUTO_TEST_CASE(test_reverse_func)
{
	Node* node = buildOneTwoThree();
	Node** ref_head = &node;

	reverse(ref_head);

	BOOST_REQUIRE(val_nth(ref_head, 0) == 3);
	BOOST_REQUIRE(val_nth(ref_head, 1) == 2);
	BOOST_REQUIRE(val_nth(ref_head, 2) == 1);

	free(node);
}

BOOST_AUTO_TEST_CASE(test_recursive_reverse_func)
{
	Node* node = buildOneTwoThree();
	Node** ref_head = &node;

	recursive_reverse(ref_head);

	BOOST_REQUIRE(val_nth(ref_head, 0) == 3);
	BOOST_REQUIRE(val_nth(ref_head, 1) == 2);
	BOOST_REQUIRE(val_nth(ref_head, 2) == 1);

	free(node);
}

BOOST_AUTO_TEST_SUITE_END()
