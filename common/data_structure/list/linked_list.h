#include <iostream>
#include <string>
#include <memory>

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

/// delete back given a head
template <class T>
T delete_back(shared_ptr<NodeT<T>>* ref_head);

/// delete nth position given a head
template <class T>
T delete_n(int n, shared_ptr<NodeT<T>>* ref_head);

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