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

template <typename T>
void push_n(T newdata, shared_ptr<NodeT<T>>* ref_head, int n)
{
	if (n < 0)
		return;

	shared_ptr<NodeT<T>>* curPtr = ref_head;
	int curPos = n;
	while (*curPtr != nullptr && n > 0) {
		curPtr = &((*curPtr)->next);
		n--;
	}

	if (n > 0) {
		try {
			std::cout << "Throwing push_n error: index for pushing too large!" << std::endl;
			throw n;
		} catch (int i) {
			std::cout << "pos is <<" << i << ">> longer than the list length" << std::endl;
			return;
		}
	}

	push_front(newdata, curPtr);
}

template void push_n(int, shared_ptr<NodeT<int>>*, int);
template void push_n(std::string, shared_ptr<NodeT<std::string>>*, int);

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

template <typename T>
int count(T value, shared_ptr<NodeT<T>>* ref_head)
{
	auto curPtr = ref_head;
	int times = 0;
	while (*curPtr != nullptr) {
		if ((*curPtr)->value == value) {
			times ++;
		}
		curPtr = &((*curPtr)->next);
	}
	return times;
}
template int count(int, shared_ptr<NodeT<int>>*);
template int count(std::string, shared_ptr<NodeT<std::string>>*);

template <typename T>
T val_nth(int n, const shared_ptr<NodeT<T>>* ref_head)
{
	assert(n >= 0 && "val_nth error: negative index!");

	int curPos = n;
	auto curPtr = ref_head;
	while (*curPtr != nullptr && curPos > 0) {
		curPtr = &((*curPtr)->next);
		curPos --;
	}

	assert(curPos == 0 && "val_nth error: index for accessing is not exist!");

	return (*curPtr)->value;
}

template int val_nth(int, const shared_ptr<NodeT<int>>*);
template std::string val_nth(int, const shared_ptr<NodeT<std::string>>*);

template <typename T>
void delete_list(shared_ptr<NodeT<T>>* ref_head)
{
	/// Since use shared_ptr, only deallocate the memory that the ref_head is pointing to
	*ref_head = nullptr;
}

template void delete_list(shared_ptr<NodeT<int>>*);
template void delete_list(shared_ptr<NodeT<std::string>>*);

template <typename T>
T delete_front(shared_ptr<NodeT<T>>* ref_head)
{
	assert(ref_head != nullptr && "delete_front error: list is empty!");
	auto curPtr = *ref_head;
	*ref_head = (*ref_head)->next;
	return curPtr->value;
}
template int delete_front(shared_ptr<NodeT<int>>*);
template std::string delete_front(shared_ptr<NodeT<std::string>>*);

template <class T>
T delete_n(int n, shared_ptr<NodeT<T>>* ref_head)
{
	assert(n >= 0 && "delete_n func error: n is negative!");
	auto curPtr = ref_head;
	int curPos = n;
	T output;
	while (*curPtr != nullptr && curPos > 1) {
		curPtr = &((*curPtr)->next);
		curPos --;
	}
	assert(curPos == 1 && "delete_n error: n overflow the total length!");
	assert((*curPtr)->next != nullptr && "delete_n error: no such node in length n");

	output = (*curPtr)->next->value;
	if ((*curPtr)->next->next == nullptr) {
		(*curPtr)->next = nullptr;
	} else {
		(*curPtr)->next = (*curPtr)->next->next;
	}
	return output;
}

template int delete_n(int, shared_ptr<NodeT<int>>*);
template std::string delete_n(int, shared_ptr<NodeT<std::string>>*);

template class NodeT<int>;
template class NodeT<double>;
template class NodeT<std::string>;




}
}

