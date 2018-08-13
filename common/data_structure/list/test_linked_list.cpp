#include "linked_list.h"

using namespace std;
using namespace common::list;

Node* test_create_head()
{
	auto node = create_dummy(11);
	return node;
}

void test_push_front_one_to_five(Node** ref_head)
{
	for (int i=5;i>0;i--) {
		push_front(ref_head, i);
	}
}

void test_push_back_six_to_ten(Node** ref_head)
{
	for (int i=6;i<11;i++) {
		push_back(ref_head, i);
	}
}

void test_push_by_position(Node** ref_head)
{
	for (int i=11;i<16;i++) {
		push_n(ref_head, i, 5);
	}
}

void print(Node** ref_head)
{
	std::cout << *ref_head << std::endl;
}

void test_count_func(Node** ref_head, int val)
{
	auto s = count(ref_head, val);
	std::cout << "times of " << val << " in the list is: " << s << std::endl;
}

void test_val_nth_func(Node** ref_head, int pos)
{
	int val = val_nth(ref_head, pos);
	std::cout << "val in the " << pos << " position is: " << val << std::endl;
}

void test_delete_list_func(Node** ref_head)
{
	delete_list(ref_head);
}

void test_delete_front_func(Node** ref_head)
{
	std::cout << "delete front: " << delete_front(ref_head) << std::endl;
}

void test_delete_n_func(Node** ref_head, int n)
{
	std::cout << "delete " << n << "th: " << delete_n(ref_head, n) << " from the list" << std::endl;
}

void test_sorted_insert(Node** ref_head, Node* node) {
	sorted_insert(ref_head, node);
}

void test_append(Node** head_one, Node** head_two) {
	std::cout << "test appending two lists" << std::endl;
	append(head_one, head_two);
}

void test_insert_sort(Node** ref_head)
{
	std::cout << "test insert sort" << std::endl;
	insert_sort(ref_head);
}

void test_remove_duplicate(Node** ref_head)
{
	std::cout << "test remove duplicate" << std::endl;
	remove_duplicate(ref_head);
}

void test_front_back_spilt(Node** ref_head,
							Node** front_head,
							Node** back_head)
{
	front_back_spilt(ref_head, front_head, back_head);
}

void test_move_node(Node** dest_head,
	Node** source_head) 
{
	move_node(dest_head, source_head);
}

void test_alternating_spilt(Node** ref_head,
					Node** first_ref_head,
					Node** second_ref_head)
{
	alternating_spilt(ref_head, first_ref_head, second_ref_head);
}

Node* test_shuffle_merge(Node** first_ref, Node** second_ref)
{
	return shuffle_merge(first_ref, second_ref);
}

int main() {

	auto head = test_create_head();
	//std::cout << head << std::endl;
	test_push_front_one_to_five(&head);
	print(&head);

	test_push_back_six_to_ten(&head);
	print(&head);

	test_push_by_position(&head);
	print(&head);

	test_count_func(&head, 11);

	test_val_nth_func(&head, 3);

	//test_delete_list_func(&head);
	test_delete_front_func(&head);
	print(&head);

	test_delete_n_func(&head, 14);
	print(&head);

	// auto node = create_dummy(0);
	// auto build = buildOneTwoThree();
	// print(&build);
	// test_sorted_insert(&build, node);
	// print(&build);

	print(&head);
	Node* headTwo = create_dummy(10);

	test_append(&head, &headTwo);
	print(&head);
	// print(&headTwo);


	test_insert_sort(&head);
	print(&head);

	test_remove_duplicate(&head);
	print(&head);

	std::cout << "length of list: " << length(head) << std::endl;

	Node* front_head = NULL;
	Node* back_head = NULL;

	test_front_back_spilt(&(head), &front_head, &back_head);
	print(&front_head);
	print(&back_head);

	auto dest_head = buildOneTwoThree();
	auto source_head = buildOneTwoThree();
	test_move_node(&dest_head, &source_head);
	print(&dest_head);
	print(&source_head);


	auto head1 = create_dummy();
	auto head2 = create_dummy();
	
	test_alternating_spilt(&head, &head1, &head2);
	print(&head);
	print(&head1);
	print(&head2);

	auto first_head = buildOneTwoThree();
	auto second_head = buildOneTwoThree();
	auto new_head = test_shuffle_merge(&first_head, &second_head);
	std::cout << "aaa" << new_head << std::endl;
	//print(&first_head);
}