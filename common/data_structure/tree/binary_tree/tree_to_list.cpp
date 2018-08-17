#include "tree_to_list.h"

using namespace std;
namespace common {
namespace binary_tree {

void join(Node* a, Node* b)
{
	if (a == NULL || b == NULL) {
		return;
	}
	a->right = b;
	b->left = a;
}

Node* buildDoubleLinkedListThreeValues(int a, int b, int c)
{
	Node* node1 = new_node(a);
	Node* node2 = new_node(b);
	Node* node3 = new_node(c);

	node1->left = node3;
	node1->right = node2;
	node2->left = node1;
	node2->right = node3;
	node3->left = node2;
	node3->right = node1;
	return node1;
}

Node* append(Node* a, Node* b)
{
	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	Node* aLast = a->left;
	Node* bLast = b->left;

	join(aLast, b);
	join(bLast, a);
	return a;
}

Node* treeToList(Node* root)
{
	if (root == NULL)
		return NULL;

	Node* first = treeToList(root->left);
	Node* second = treeToList(root->right);

	root->left = root;
	root->right = root;

	return append(append(first, root), second);
}

void printDoubleLinkedList(Node* root)
{
	Node* cur = root;
	while (cur != NULL) {
		std::cout << cur->val << " ";
		cur = cur->right;
		if (cur == root)
			break;
	}
}

}
}