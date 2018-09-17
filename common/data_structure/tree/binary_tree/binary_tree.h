#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <limits.h>
#include "../../../visualize/print.h"

#ifndef _COMMON_DATA_STRUCTURE_BINARY_TREE_
#define _COMMON_DATA_STRUCTURE_BINARY_TREE_

#define NUMBER_VERY_LARGE INT_MAX
#define NUMBER_VERY_SMALL INT_MIN

using namespace std;
namespace common {
namespace binary_tree {

struct Node {
	int val;
	Node* left = NULL;
	Node* right = NULL;
	/// use "bf" as "balance factor for a node", meaning the depth of right subtree minus
	/// depth of left subtree
	int bf;
};

/// Given a binary tree, check if the target exists and return a bool
bool look_up(Node* node, int target);

/// Given a binary tree, check if the target exists and if exist, 
/// return the specific node, otherwise, return NULL
Node* find(Node* node, int target);

/// help function to create a new node
Node* new_node(int value);

/// Given a binary tree, insert the target into the right place
/// and return the modified node
void insert(Node* &node, int value);

/// Given a BST, delete the node with the val target
/// and maintain the structure of remaining BST
/// if value not found, simply return and do nothing
void remove(Node* &node, int value);

/// create 123 binary tree
///   2
/// 1   3
Node* buildOneTwoThree();

/// given a node, count the size of it
int size(Node* node);

/// given a node, calculate the maximum depth of it
int maxDepth(Node* node);

/// given a node, return the minimum data value in the tree
int minValue(Node* node);

/// given a node, return the maximum data value in the tree
int maxValue(Node* node);

/// given a node, return the leftmost (minimum) node donw of it
Node* minNode(Node* node);

/// given a node, return the rightmost (maximum) node donw of it
Node* maxNode(Node* node);

/// given a node, print out an increasing order of all values in node
void printSortedOrder(Node* node);

/// given a node, print out an traversal order (bottom-up, left-right)
void printPostOrder(Node* node);

/// given a node and a number, 
/// calculate the sum of each path, 
/// return true if any of the sum match the number
bool hasPathSum(Node* node, int sum);

/// given a node, print all the paths
void printPath(Node* node);

/// recursive function for printPath()
void printPathsRecur(Node* node, vector<int> vec);

/// given a node, change it to become a mirror node
///      5                  5                 
///    3   8 ->           8   3          
///   2 4                    4  2  
void mirror(Node* node);

/// given a tree, create a new duplicate node of each node
/// insert the duplicate as the left child of the original node
/// the modified node should still be a BST
void doubleTree(Node* node);

/// given two trees, return true if they are identical, false otherwise
bool sameTree(Node* node1, Node* node2);

/// visualize the node
void print(Node* node, int indent=0);

/// given a value N representing 1 to n, count the #num of 
/// different structures that these number will maintain 
/// in a BST
/// idea is using a loop, count possible values in left and right
/// use multiplication (left*right) for the sum
int countTrees(int n);

/// given a tree, check to find if the tree is a BST or not
/// idea is, use recursion and pass the largest and smallest value that
/// the node can have
bool isBST(Node* node);

/// implement function for isBST()
bool isBSTimplement(Node* node, int max, int min);


} // namespace binary_tree
} // namespace common

namespace common {
namespace balanced_btree {

/// function to insert a node using balancing strategy
void insertNode(common::binary_tree::Node* &node, int val);

/// function to insert a node, and return an integer showing the change in depth in the tree
/// which is used to correct the balance factor (bf) ub the parent nodes
int insertAVL(common::binary_tree::Node* &node, int val);

/// function to fix left imbalance
/// if node->bf = node->left->bf, perform single rotation
/// if node->bf != node->left->bf, perform double rotation
void fixLeftImbalance(common::binary_tree::Node* &node);

/// function to fix right imbalance
/// if node->bf = node->right->bf, perform single rotation
/// if node->bf != node->right->bf, perform double rotation
void fixRightImbalance(common::binary_tree::Node* &node);

/// function to rotate left
void rotateLeft(common::binary_tree::Node* &node);

/// function to rotate right
void rotateRight(common::binary_tree::Node* &node);


} // namespace balanced_btree
} // namespace common

#endif