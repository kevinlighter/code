#include <iostream>
#include <string>
#include <memory>
#include <assert.h>

using namespace std;

namespace common {
namespace list {

template <class T>
struct NodeT {

	NodeT() = default;

	NodeT(T data) {
		this->value = data;
	}

	T value;
	/// Shared_ptr default to nullptr
	shared_ptr<NodeT<T>> next;

};

/// construct a dummy head and return the share ptr of it
template <class T>
shared_ptr<NodeT<T>> create_dummy();

template <class T>
shared_ptr<NodeT<T>> create_dummy(T data);


/// Get the length of the list
template <class T>
int length(shared_ptr<NodeT<T>> head);

/// push to the front given a head
template <class T>
void push_front(T newdata, shared_ptr<NodeT<T>>* ref_head);

/// push to the specific location
template <class T>
void push_n(T newdata, shared_ptr<NodeT<T>>* ref_head, int n);

/// push to the back given a head
template <class T>
void push_back(T newdata, shared_ptr<NodeT<T>>* ref_head);

/// delete front given a head
template <class T>
T delete_front(shared_ptr<NodeT<T>>* ref_head);

/// delete nth position given a head
template <class T>
T delete_n(int n, shared_ptr<NodeT<T>>* ref_head);

/// function to count the number of appearance of a value
template <class T>
int count(T value, shared_ptr<NodeT<T>>* ref_head);

/// function to get the nth value in a list
template <class T>
T val_nth(int n, const shared_ptr<NodeT<T>>* ref_head);

/// function to delete a list, by deallocating all the memory
template <class T>
void delete_list(shared_ptr<NodeT<T>>* ref_head);
 
/// function to take a sorted list with increasing order, and a new
/// node of some specific number, insert the new node to the right position
template <class T>
void sorted_insert(shared_ptr<NodeT<T>>* ref_head, shared_ptr<NodeT<T>> inserted_head);

/// function to take two lists and append the second to the first list
template <class T>
void append(shared_ptr<NodeT<T>>* first_ref_head, shared_ptr<NodeT<T>>* second_ref_head);

/// given a list, rearrange it to be increasing sorted
template <class T>
void insert_sort(shared_ptr<NodeT<T>>* ref_head);

/// function to remove duplicate element in a list, given a
/// already sorted increasing list
template <class T>
void remove_duplicate(shared_ptr<NodeT<T>>* ref_head);

/// function to spilt the list into front and back list
/// use a trick of a slow pointer and fast pointer
template <class T>
void front_back_spilt(shared_ptr<NodeT<T>>* ref_head,
					shared_ptr<NodeT<T>>* front_ref_head,
					shared_ptr<NodeT<T>>* back_ref_head);

/// function to move the first node of second list to the front 
/// of the first list
template <class T>
void move_node(shared_ptr<NodeT<T>>* dest_head, shared_ptr<NodeT<T>>* source_head);

/// input a list, output two list which is the alternating element
/// of the original list: so if A = {a,b,a,b,a}, then output two lists
/// b = {a,a,a} and c = {b,b}
template <class T>
void alternating_spilt(shared_ptr<NodeT<T>>* ref_head,
					shared_ptr<NodeT<T>>* first_ref_head,
					shared_ptr<NodeT<T>>* second_ref_head);

/// function to merge two list alternatively, so if 
/// input a = {1,2,3}, b = {4,5,6}, output list should be 
/// C = {1,4,2,5,3,6}
template <class T>
void shuffle_merge(shared_ptr<NodeT<T>>* first_head,
					shared_ptr<NodeT<T>>* second_head,
					shared_ptr<NodeT<T>>* ref_head);

/// Build One Two Three list
shared_ptr<NodeT<int>> BuildOneTwoThree();

/// Print list function
template <class T>
ostream& operator<<(ostream& s, shared_ptr<NodeT<T>> head)
{
	if (head == nullptr) {
		std::cout << "end";
		return s;
	}

	s << head->value << " -> ";
	s << (head->next);
	return s;
}

using Node = NodeT<int>;
using Nodei = NodeT<int>;
using Noded = NodeT<double>;
using Nodes = NodeT<std::string>;


}
}