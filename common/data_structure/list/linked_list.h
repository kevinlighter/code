#include <iostream>
#include <assert.h>

using namespace std;

namespace common {
namespace list {

struct Node {
	Node() = default;
	Node(int data) {
		this->val = data;
	}
	int val;
	Node* next = NULL;
};

Node* create_dummy();

Node* create_dummy(int data);

/// Length function to get the length of a list
int length(Node* head);

/// Build one two three sequentially
Node* buildOneTwoThree();

/// Insert a node in the front of the list
void push_front(Node** ref_head, int newData);

/// Insert a node in the back of the list
void push_back(Node** ref_head, int newData);

/// Insert a node in the nth location in the list
void push_n(Node** ref_head, int newData, int n);

/// function to count the number of occurance of value in nodes of a list
int count(Node** ref_head, int value);

/// delete the front node of a list
int delete_front(Node** ref_head);

/// delete the nth node of a list
int delete_n(Node** ref_head, int n);

/// get the nth node val in the list
int val_nth(Node** ref_head, int n);

/// delete the whole list
void delete_list(Node** ref_head);

/// function to take a sorted list with increasing order, and a new
/// node of some specific number, insert the new node to the right position
void sorted_insert(Node** ref_head, Node* inserted_head);

/// function to take two lists and append the second to the first list
void append(Node** first_ref_head, Node** second_ref_head);

/// given a list, rearrange it to be increasing sorted
void insert_sort(Node** ref_head);

/// function to remove duplicate element in a list, given a
/// already sorted increasing list
void remove_duplicate(Node** ref_head);

/// function to spilt the list into front and back list
/// use a trick of a slow pointer and fast pointer
void front_back_spilt(Node** ref_head,
					Node** front_ref_head,
					Node** back_ref_head);

/// function to move the first node of second list to the front 
/// of the first list
void move_node(Node** dest_head, Node** source_head);

/// input a list, output two list which is the alternating element
/// of the original list: so if A = {a,b,a,b,a}, then output two lists
/// b = {a,a,a} and c = {b,b}
/// with the help function move_node();
void alternating_spilt(Node** ref_head,
					Node** first_ref_head,
					Node** second_ref_head);

/// function to merge two list alternatively, so if 
/// input a = {1,2,3}, b = {4,5,6}, output list should be 
/// C = {1,4,2,5,3,6}
/// method: 1. move to the back of each node
/// 2. use move_node function to alternatively add 
/// 3. if one list runs out, the other list puts on
Node* shuffle_merge(Node** first_head, Node** second_head);

/// function to merge two increasing lists to one list with
/// increasing order
/// method 1: use move_node iteratively
/// method 2: use move_node recursively
Node* sorted_merge(Node** first_head, Node** second_head);

/// given a list, split the list into two smaller lists, recursively 
/// sort those lists, and finally merge together the two sorted lists into a single list
/// use function front_back_spilt() and sorted_merge()
void merge_sort(Node** ref_head);

/// given two lists of increasing order, return a new list of the intersection of them
/// should not be changing the original lists
Node* sorted_intersect(Node** first_head, Node** second_head);

/// reverse a list using move_node function
void reverse(Node** ref_head);

/// reverse a list using recursion
void recursive_reverse(Node** ref_head);

/// Print list function
ostream& operator<<(ostream& s, Node* head);



} // namespace list
} // namespace common