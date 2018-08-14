#include "linked_list.h"

using namespace std;

namespace common {
namespace list {


Node* create_dummy()
{
	Node* newnode = new Node();
	return newnode;
}


Node* create_dummy(int data)
{
	Node* newnode = new Node(data);
	return newnode;
}

int length(Node* head)
{
	int n = 0;
	Node* cur = head;
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}

	return n;
}

ostream& operator<<(ostream& s, Node* head)
{
	if (head == NULL) {
		std::cout << "end";
		return s;
	}

	s << head->val << " -> ";
	s << (head->next);
	return s;
}

void push_front(Node** ref_head, int newData)
{
	Node* newNode = new Node(newData);
	newNode->next = *ref_head;
	/// copy assignment, not by reference
	*ref_head = newNode;
}

void push_back(Node** ref_head, int newData)
{
	Node** curPtr = ref_head;
	while (*curPtr != nullptr)
	{
		curPtr = &((*curPtr)->next);
	}
	push_front(curPtr, newData);
}

Node* buildOneTwoThree()
{
	Node* head = NULL;
	for (int i = 3;i > 0;i--) {
		push_front(&head, i);
	}
	return head;
}

void push_n(Node** ref_head, int newData, int n)
{
	if (n < 0)
		return;

	auto curPtr = ref_head;
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

	push_front(curPtr, newData);
}

int count(Node** ref_head, int value)
{
	auto curPtr = ref_head;
	int times = 0;
	while (*curPtr != NULL) {
		if ((*curPtr)->val == value) {
			times ++;
		}
		curPtr = &((*curPtr)->next);
	}
	return times;
}

int delete_front(Node** ref_head)
{
	assert(ref_head != NULL && "delete_front error: list is empty!");
	auto curPtr = *ref_head;
	int result = (*ref_head)->val;
	*ref_head = (*ref_head)->next;
	free(curPtr);
	return result;
}

int delete_n(Node** ref_head, int n)
{
	assert(n >= 0 && "delete_n func error: n is negative!");
	auto curPtr = ref_head;
	int curPos = n;
	int output;
	while (*curPtr != nullptr && curPos > 1) {
		curPtr = &((*curPtr)->next);
		curPos --;
	}

	assert(curPos == 1 && "delete_n error: n overflow the total length!");
	assert((*curPtr)->next != nullptr && "delete_n error: no such node in length n");

	output = (*curPtr)->next->val;
	if ((*curPtr)->next->next == nullptr) {
		(*curPtr)->next = nullptr;
	} else {
		(*curPtr)->next = (*curPtr)->next->next;
	}
	return output;
}

int val_nth(Node** ref_head, int n)
{
	assert(n >= 0 && "val_nth error: negative index!");

	int curPos = n;
	auto curPtr = ref_head;
	while (*curPtr != nullptr && curPos > 0) {
		curPtr = &((*curPtr)->next);
		curPos --;
	}

	assert(curPos == 0 && "val_nth error: index for accessing is not exist!");

	return (*curPtr)->val;
}

void delete_list(Node** ref_head)
{
	auto curPtr = *ref_head;
	Node* next;
	while (curPtr != NULL) {
		next = curPtr->next;
		free(curPtr);
		curPtr = next;
	}
	*ref_head = NULL;
}

void sorted_insert(Node** ref_head, Node* inserted_head)
{
	int value = inserted_head->val;
	auto curPtr = *ref_head;

	assert(inserted_head->next == NULL && "sorted_insert error: inserted_head is a list, not a node!");

	assert(curPtr != NULL && "sorted_insert error: input ref head is nullptr");
	if (curPtr->val > inserted_head->val) {
		inserted_head->next = curPtr;
		*ref_head = inserted_head;
		return;
	}

	while (curPtr != NULL) {
		if (curPtr->next == NULL) {
			curPtr->next = inserted_head;
			return;
		} else {
			if (curPtr->val <= value && curPtr->next->val > value) {
				inserted_head->next = curPtr->next;
				curPtr->next = inserted_head;
				return;
			} else {
				curPtr = curPtr->next;
			}
		}
	}
}

void append(Node** first_ref_head, Node** second_ref_head)
{
	auto curPtr = *first_ref_head;
	Node* pre_head = NULL;
	while (curPtr != NULL) {
		pre_head = curPtr;
		curPtr = curPtr->next;
	}
	pre_head->next = *second_ref_head;
	second_ref_head = NULL;
}

void insert_sort(Node** ref_head)
{
	auto curPtr = *ref_head;
	assert(curPtr != NULL && "insert_sort error: input list is empty!");
	auto basenode = create_dummy(curPtr->val);
	curPtr = curPtr->next;
	while (curPtr != NULL) {
		auto newnode = create_dummy(curPtr->val);
		sorted_insert(&basenode, newnode);
		curPtr = curPtr->next;
	}
	free(*ref_head);
	*ref_head = basenode;
}

void remove_duplicate(Node** ref_head)
{
	auto curPtr = *ref_head;
	if (curPtr == NULL) {
		return;
	}
	while (curPtr->next != NULL) {
		if (curPtr->val == curPtr->next->val) {
			Node* nextNext = curPtr->next->next;
			free(curPtr->next);
			curPtr->next = nextNext;
		} else {
			curPtr = curPtr->next;
		}
	}
}

void front_back_spilt(Node** ref_head,
					Node** front_ref_head,
					Node** back_ref_head)
{
	auto fastPtr = *ref_head;
	auto slowPtr = *ref_head;
	*front_ref_head = *ref_head;

	if (fastPtr == NULL) {
		back_ref_head = NULL;
		return;
	}

	if (fastPtr->next == NULL) {
		back_ref_head = NULL;
		return;
	}

	while (fastPtr != NULL && fastPtr->next != NULL) {
		if (fastPtr->next->next != NULL) {
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
		} else {
			break;
		}

	}
	*back_ref_head = slowPtr->next;
	slowPtr->next = NULL;
}

void move_node(Node** dest_head, Node** source_head)
{
	auto destPtr = *dest_head;
	auto sourcePtr = *source_head;
	*source_head = (*source_head)->next;
	sourcePtr->next = destPtr;
	*dest_head = sourcePtr;
}

void alternating_spilt(Node** ref_head,
					Node** first_ref_head,
					Node** second_ref_head)
{
	int i=0;
	Node* first_Ptr = NULL;
	Node* second_Ptr = NULL;
	while (*ref_head != NULL) {
		if (i%2 == 0) {
			move_node(&first_Ptr, ref_head);
		} else {
			move_node(&second_Ptr, ref_head);
		}
		i++;
	}
	*first_ref_head = first_Ptr;
	*second_ref_head = second_Ptr;
}

Node* shuffle_merge(Node** first_head,
					Node** second_head)
{
	Node* new_head = NULL;
	Node** last_node_ref = &new_head;

	while (1) { 
		if (*first_head == NULL) {
			*last_node_ref = *second_head;
			break;
		} else if (*second_head == NULL) {
			*last_node_ref = *first_head;
			break;
		} else {
			move_node(last_node_ref, first_head);
			last_node_ref = &((*last_node_ref)->next);
			move_node(last_node_ref, second_head);
			last_node_ref = &((*last_node_ref)->next);
		}
	}
	//std::cout << length<T>(*ref_head) << std::endl;
	return new_head;
}

Node* sorted_merge(Node** first_head, Node** second_head)
{
	Node* new_head = NULL;
	Node** last_node_ref = &new_head;

	while (1) {
		if (*first_head == NULL) {
			*last_node_ref = *second_head;
			break;
		} else if (*second_head == NULL) {
			*last_node_ref = *first_head;
			break;
		} else {
			if ((*first_head)->val < (*second_head)->val) {
				move_node(last_node_ref, first_head);
			} else {
				move_node(last_node_ref, second_head);
			}
			last_node_ref = &((*last_node_ref)->next);
		}
	}
	return new_head;
}

void merge_sort(Node** ref_head)
{
	if (length(*ref_head) == 1 || length(*ref_head) == 0)
		return;
	/// spilt the ref list into smaller lists
	Node* firstPtr = new Node();
	Node* secondPtr = new Node();
	front_back_spilt(ref_head, &firstPtr, &secondPtr);
	merge_sort(&firstPtr);
	merge_sort(&secondPtr);
	*ref_head = sorted_merge(&firstPtr, &secondPtr);
}

Node* sorted_intersect(Node** first_head, Node** second_head)
{
	Node* resultPtr = NULL;
	Node** ref_head = &resultPtr;

	auto firstPtr = *first_head;
	auto secondPtr = *second_head;

	while (1) {
		if (firstPtr == NULL || secondPtr == NULL) {
			break;
		} 
		if (firstPtr->val == secondPtr->val) {
			push_front(ref_head, firstPtr->val);
			firstPtr = firstPtr->next;
		} else {
			if (firstPtr->val < secondPtr->val) {
				firstPtr = firstPtr->next;
			} else {
				secondPtr = secondPtr->next;
			}
		}
	}
	return resultPtr;
}

void reverse(Node** ref_head)
{
	if (*ref_head == NULL) {
		return;
	}
	Node* newnode = NULL;
	Node** new_ref = &newnode;
	while (*ref_head != NULL) {
		move_node(new_ref, ref_head);
	}
	*ref_head = *new_ref;

}

void recursive_reverse(Node** ref_head)
{
	Node* first = NULL;
	Node* rest = NULL;

	if (*ref_head == NULL) {
		return; // Base case for empty list
	} 

	first = *ref_head;
	rest = (*ref_head)->next;

	if (rest == NULL) {
		return; // if rest is empty, return since the list is done
	}

	recursive_reverse(&rest);

	first->next->next = first;
	first->next = NULL;

	*ref_head = rest;
}




}
}

