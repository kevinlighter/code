#include "linked_list.h"

using namespace std;

namespace common {
namespace list {


template <typename T>
shared_ptr<NodeT<T>> create_dummy()
{
	return std::make_shared<NodeT<T>>(NodeT<T>());
}

template shared_ptr<NodeT<int>> create_dummy();
template shared_ptr<NodeT<std::string>> create_dummy();

template <typename T>
shared_ptr<NodeT<T>> create_dummy(T data)
{
	return std::make_shared<NodeT<T>>(NodeT<T>(data));
}

template shared_ptr<NodeT<int>> create_dummy(int);
template shared_ptr<NodeT<std::string>> create_dummy(std::string);

template <typename T>
int length(shared_ptr<NodeT<T>> head)
{
	int n = 0;
	auto cur = head;
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}
	return n;
}

template int length(shared_ptr<NodeT<int>>);
template int length(shared_ptr<NodeT<std::string>>);

template <typename T>
void push_front(T newdata, shared_ptr<NodeT<T>>* ref_head)
{
	shared_ptr<NodeT<T>> newNode = std::make_shared<NodeT<T>>(NodeT<T>(newdata));
	newNode->next = *ref_head;
	/// copy assignment, not by reference
	*ref_head = newNode;
}

template void push_front(int, shared_ptr<NodeT<int>>*);
template void push_front(std::string, shared_ptr<NodeT<std::string>>*);

shared_ptr<NodeT<int>> BuildOneTwoThree()
{
	shared_ptr<NodeT<int>> head;
	for (int i = 3;i > 0;i--) {
		push_front(i,&head);
	}
	return head;
}

// void push_n(T newdata, shared_ptr<NodeT<T>>* ref_head, int n)
// {
// 	if (n < 0)
// 		return;

// 	auto newnode = create_dummy(newdata);
// 	auto curPtr = ref_head;
// 	while (n > 0) {
// 		if (curPtr != nullptr) {
// 			curPtr = &(curPtr->next);
// 			n --;
// 		} else {
// 			return;
// 		}
// 	}


// }

template <typename T>
void push_back(T newdata, shared_ptr<NodeT<T>>* ref_head)
{
	shared_ptr<NodeT<T>>* curPtr = ref_head;
	while (*curPtr != nullptr)
	{
		curPtr = &((*curPtr)->next);
	}
	push_front(newdata, curPtr);
}

template void push_back(int, shared_ptr<NodeT<int>>*);
template void push_back(std::string, shared_ptr<NodeT<std::string>>*);


template class NodeT<int>;
template class NodeT<double>;
template class NodeT<std::string>;




}
}

