
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
	

BOOST_AUTO_TEST_SUITE_END()


// Node* test_shuffle_merge(Node** first_ref, Node** second_ref)
// {
// 	return shuffle_merge(first_ref, second_ref);
// }

// Node* test_sorted_merge(Node** first_ref, Node** second_ref)
// {
// 	return sorted_merge(first_ref, second_ref);
// }

// void test_sorted_intersect() {
// 	auto head1 = create_dummy(0);
// 	push_back(&head1, 2);
// 	push_back(&head1, 4);
// 	push_back(&head1, 6);
// 	push_back(&head1, 8);
// 	push_back(&head1, 10);

// 	auto head2 = create_dummy(1);
// 	push_back(&head2, 3);
// 	push_back(&head2, 4);
// 	push_back(&head2, 7);
// 	push_back(&head2, 9);
// 	push_back(&head2, 10);

// 	std::cout << "intersect1: " << head1 << std::endl;
// 	std::cout << "intersect2: " << head2 << std::endl;

// 	auto result = sorted_intersect(&head1, &head2);

// 	std::cout << "intersect 3: " << result << std::endl;
// }

// void test_reverse()
// {
// 	auto head = buildOneTwoThree();
// 	reverse(&head);
// 	std::cout << "1:" << head << std::endl;
// }

// void test_recursive_reverse()
// {
// 	auto head = buildOneTwoThree();
// 	recursive_reverse(&head);
// 	std::cout << "1:" << head << std::endl;
// }


// int main(int argc, char* argv[]) {

// 	auto head = test_create_head();
// 	//std::cout << head << std::endl;
// 	test_push_front_one_to_five(&head);
// 	print(&head);

// 	test_push_back_six_to_ten(&head);
// 	print(&head);

// 	test_push_by_position(&head);
// 	print(&head);

// 	test_count_func(&head, 11);

// 	test_val_nth_func(&head, 3);

// 	//test_delete_list_func(&head);
// 	test_delete_front_func(&head);
// 	print(&head);

// 	test_delete_n_func(&head, 14);
// 	print(&head);

// 	// auto node = create_dummy(0);
// 	// auto build = buildOneTwoThree();
// 	// print(&build);
// 	// test_sorted_insert(&build, node);
// 	// print(&build);

// 	print(&head);
// 	Node* headTwo = create_dummy(10);

// 	test_append(&head, &headTwo);
// 	print(&head);
// 	// print(&headTwo);


// 	test_insert_sort(&head);
// 	print(&head);

// 	test_remove_duplicate(&head);
// 	print(&head);

// 	std::cout << "length of list: " << length(head) << std::endl;

// 	Node* front_head = NULL;
// 	Node* back_head = NULL;

// 	test_front_back_spilt(&(head), &front_head, &back_head);
// 	print(&front_head);
// 	print(&back_head);

// 	auto dest_head = buildOneTwoThree();
// 	auto source_head = buildOneTwoThree();
// 	test_move_node(&dest_head, &source_head);
// 	print(&dest_head);
// 	print(&source_head);


// 	auto head1 = create_dummy();
// 	auto head2 = create_dummy();
	
// 	test_alternating_spilt(&head, &head1, &head2);
// 	print(&head);
// 	print(&head1);
// 	print(&head2);

// 	insert_sort(&head1);

// 	auto first_head = buildOneTwoThree();
// 	auto second_head = buildOneTwoThree();

// 	auto new_head = test_sorted_merge(&head1, &second_head);
// 	std::cout << "aaa: " << new_head << std::endl;

// 	push_back(&new_head, 5);
// 	merge_sort(&new_head);

// 	std::cout << std::endl;
// 	print(&new_head);

// 	test_sorted_intersect();

// 	test_reverse();

// 	test_recursive_reverse();

// }