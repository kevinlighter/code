#include "linked_list.h"

using namespace std;
using namespace common::list;

shared_ptr<NodeT<int>> test_create_head()
{
	auto node = create_dummy<int>(11);
	return node;
}

void test_push_front_one_to_five(shared_ptr<NodeT<int>>* ref_head)
{
	for (int i=5;i>0;i--) {
		push_front<int>(i, ref_head);
	}
}

void test_push_back_six_to_ten(shared_ptr<NodeT<int>>* ref_head)
{
	for (int i=6;i<11;i++) {
		push_back<int>(i, ref_head);
	}
}

void test_push_by_position(shared_ptr<NodeT<int>>* ref_head)
{
	for (int i=11;i<16;i++) {
		push_n<int>(i, ref_head, 0);
	}
}

void print(shared_ptr<NodeT<int>>* ref_head)
{
	std::cout << *ref_head << std::endl;
}

void test_count_func(shared_ptr<NodeT<int>>* ref_head, int val)
{
	auto s = count<int>(val, ref_head);
	std::cout << "times of " << val << " in the list is: " << s << std::endl;
}

void test_val_nth_func(shared_ptr<NodeT<int>>* ref_head, int pos)
{
	auto val = val_nth(pos, ref_head);
	std::cout << "val in the " << pos << " position is: " << val << std::endl;
}

void test_delete_list_func(shared_ptr<NodeT<int>>* ref_head)
{
	delete_list(ref_head);
}

void test_delete_front_func(shared_ptr<NodeT<int>>* ref_head)
{
	std::cout << "delete front: " << delete_front<int>(ref_head) << std::endl;
}

void test_delete_n_func(shared_ptr<NodeT<int>>* ref_head, int n)
{
	std::cout << "delete " << n << "th: " << delete_n(n, ref_head) << " from the list" << std::endl;
}

void test_sorted_insert(shared_ptr<NodeT<int>>* ref_head, shared_ptr<NodeT<int>> node) {
	sorted_insert<int>(ref_head, node);
}

void test_append(shared_ptr<NodeT<int>>* head_one, shared_ptr<NodeT<int>>* head_two) {
	std::cout << "test appending two lists" << std::endl;
	append<int>(head_one, head_two);
}

void test_insert_sort(shared_ptr<NodeT<int>>* ref_head)
{
	std::cout << "test insert sort" << std::endl;
	insert_sort(ref_head);
}

void test_remove_duplicate(shared_ptr<NodeT<int>>* ref_head)
{
	std::cout << "test remove duplicate" << std::endl;
	remove_duplicate(ref_head);
}

void test_front_back_spilt(shared_ptr<NodeT<int>>* ref_head,
							shared_ptr<NodeT<int>>* front_head,
							shared_ptr<NodeT<int>>* back_head)
{
	front_back_spilt<int>(ref_head, front_head, back_head);
}

void test_move_node(shared_ptr<NodeT<int>>* dest_head,
	shared_ptr<NodeT<int>>* source_head) 
{
	move_node<int>(dest_head, source_head);
}

int main() {

	auto head = test_create_head();
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

	// auto node = create_dummy<int>(0);
	// test_sorted_insert(&head, node);
	// print(&head);

	auto headTwo = create_dummy<int>(0);
	test_append(&head, &headTwo);
	print(&head);

	//insert_sort(&head);

	test_insert_sort(&head);
	print(&head);

	test_remove_duplicate(&head);
	print(&head);

	std::cout << "length of list: " << length<int>(head) << std::endl;

	shared_ptr<NodeT<int>> front_head;
	shared_ptr<NodeT<int>> back_head;

	test_front_back_spilt(&(head), &front_head, &back_head);
	print(&front_head);
	print(&back_head);

	auto dest_head = BuildOneTwoThree();
	auto source_head = BuildOneTwoThree();
	test_move_node(&dest_head, &source_head);
	print(&dest_head);
	print(&source_head);


}