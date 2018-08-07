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

}