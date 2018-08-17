#include "binary_tree.h"

#ifndef _COMMON_DATA_STRUCTURE_TREE_TO_LIST_
#define _COMMON_DATA_STRUCTURE_TREE_TO_LIST_

using namespace std;

namespace common {
namespace binary_tree {

/// join two nodes into a double linked list
void join(Node* a, Node* b);

/// build a doubly linked list with 1,2,3
Node* buildDoubleLinkedListThreeValues(int a, int b, int c);

/// given two circular double linked list, append them
/// and return the new list
Node* append(Node* a, Node* b);

Node* treeToList(Node* root);

void printDoubleLinkedList(Node* root);


} // namespace tree
} // namespace common

#endif