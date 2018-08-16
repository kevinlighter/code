#include "binary_tree.h"

using namespace std;
namespace common {
namespace binary_tree {

bool look_up(Node* node, int target)
{
	if (node == NULL) {
		return false;
	}

	if (node->val == target)
		return true;

	if (target < node->val) {
		return look_up(node->left, target);
	} else {
		return look_up(node->right, target);
	}
}

Node* find(Node* node, int target)
{
	if (node == NULL) {
		return NULL;
	}

	if (node->val == target)
		return node;

	if (target < node->val) {
		return find(node->left, target);
	} else {
		return find(node->right, target);
	}
}

Node* new_node(int value)
{
	Node* node = new Node();
	node->val = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* insert(Node* node, int value)
{
	if (node == NULL) {
		return new_node(value);
	}

	if (value <= node->val) {
		node->left = insert(node->left, value);
	} else {
		node->right = insert(node->right, value);
	}

	return node;
}

Node* remove(Node* node, int value)
{
	if (node == NULL)
		return NULL;

	if (value < node->val) {
		node->left = remove(node->left, value);
	} else if (value > node->val) {
		node->right = remove(node->right, value);
	/// found the node
	} else {
		if (node->left == NULL && node->right == NULL) {
			free(node);
			node = NULL;
		} // case of no children
		else if (node->left == NULL) {
			Node* temp = node;
			node = node->right;
			free(temp);
		} // case of only right children
		else if (node->right == NULL) {
			Node* temp = node;
			node = node->left;
			free(temp);
		} // case of only left children
		else {
			Node* leftMost = minNode(node->right);
			node->val = leftMost->val;
			node->right = remove(node->right, leftMost->val);
		}
	}

	return node;
}

Node* buildOneTwoThree()
{
	Node* node = NULL;
	node = insert(node, 2);
	node = insert(node, 1);
	node = insert(node, 3);
	return node;
}

void print(Node* node, int indent)
{
	if (node == NULL)
		return;

	if (indent) {
        std::cout << std::setw(indent) << ' ';
    }
	cout << node->val << std::endl;
	print(node->left, indent + 4);
	print(node->right, indent + 4);
}

int size(Node* node)
{
	if (node == NULL) {
		return 0;
	}

	return 1 + size(node->left) + size(node->right);	
}

int maxDepth(Node* node)
{
	if (node == NULL) {
		return 0;
	}

	return (maxDepth(node->left) > maxDepth(node->right) ? maxDepth(node->left)+1 : maxDepth(node->right)+1);
}

int minValue(Node* node)
{
	if (node == NULL) {
		return NUMBER_VERY_LARGE;
	}

	return (minValue(node->left) < node->val ? minValue(node->left) : node->val);
}

int maxValue(Node* node)
{
	if (node == NULL) {
		return NUMBER_VERY_SMALL;
	}

	return (maxValue(node->right) > node->val ? maxValue(node->right) : node->val);
}

Node* minNode(Node* node)
{
	if (node == NULL) {
		return NULL;
	}
	if (node->left == NULL){
		return node;
	} else {
		return minNode(node->left);
	}
}

Node* maxNode(Node* node)
{
	if (node == NULL) {
		return NULL;
	}
	if (node->right == NULL){
		return node;
	} else {
		return maxNode(node->right);
	}
}

void printSortedOrder(Node* node)
{
	if (node == NULL) {
		return;
	}

	/// first recur left to get down to the left node of bottom node
	printSortedOrder(node->left);
	/// output the value
	cout << node->val << " ";
	/// after the left recursion is done, go up a node and do the right recursion
	printSortedOrder(node->right);
}

void printPostOrder(Node* node)
{
	if (node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout << node->val << " ";
}

bool hasPathSum(Node* node, int sum)
{
	if (node == NULL) {
		return false;
	}

	if (node->left == NULL && node->val == sum) {
		return true;
	}

	if (node->right == NULL && node->val == sum) {
		return true;
	}

	return hasPathSum(node->left, sum - node->val) || hasPathSum(node->right, sum - node->val);
}

void printPath(Node* node)
{
	vector<int> vec;
	printPathsRecur(node, vec);
}

void printPathsRecur(Node* node, vector<int> vec)
{
	if (node == NULL) {
		return;
	}

	vec.push_back(node->val);
	if (node->left == NULL && node->right == NULL) {
		/// print vec here
		cout << vec << endl;
		return;
	}
	if (node->left == NULL) {
		/// print vec here
		cout << vec << endl;

		printPathsRecur(node->right, vec);
	} else if (node->right == NULL){
		/// print vec here
		cout << vec << endl;
		printPathsRecur(node->left, vec);
	} else {
		printPathsRecur(node->left, vec);
		printPathsRecur(node->right, vec);
	}
}

void mirror(Node* node)
{
	if (node == NULL)
		return;

	Node* temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirror(node->left);
	mirror(node->right);
}

void doubleTree(Node* node)
{
	if (node == NULL)
		return;

	Node* newNode = new_node(node->val);
	newNode->left = node->left;
	node->left = newNode;

	doubleTree(newNode->left);
	doubleTree(node->right);
}

bool sameTree(Node* node1, Node* node2)
{
	if (node1 == NULL && node2 == NULL) {
		return true;
	}

	if (node1 == NULL || node2 == NULL) {
		return false;
	}

	return (node1->val == node2->val) && sameTree(node1->left, node2->left) && sameTree(node1->right, node2->right);
}

int countTrees(int n)
{
	if (n <= 1) {
		return 1;
	}

	int sum = 0;
	int left, right;

	for (int root = 1; root <= n; root ++) {
		left = countTrees(root - 1);
		right = countTrees(n - root);

		sum += left*right;
	}
	return sum;
}

bool isBST(Node* node)
{
	return isBSTimplement(node, NUMBER_VERY_LARGE, NUMBER_VERY_SMALL);
}

bool isBSTimplement(Node* node, int max, int min)
{
	if (node->val < min || node->val > max)
		return false;

	if (node->left == NULL && node->right == NULL)
		return true;

	if (node->left == NULL)
		return isBSTimplement(node->right, max, node->val);

	if (node->right == NULL)
		return isBSTimplement(node->left, node->val, min);

	return isBSTimplement(node->right, max, node->val) && isBSTimplement(node->left, node->val, min);

}



}
}