#include "btree.h"

using namespace std;

namespace common {
namespace tree {
namespace BTree {

template <typename T>
NodeT<T>::NodeT(T data):
	value(data),
	left(nullptr),
	right(nullptr),
	num_of_data(1) {}

template <typename T>
void NodeT<T>::insert(T data) {
	if (data < this->value) {
		if (this->left == nullptr) {
			this->left = make_shared<NodeT<T>>(data);
		} else {
			this->left->insert(data);
		}
	} else if (data > this->value) {
		if (this->right == nullptr) {
			this->right = make_shared<NodeT<T>>(data);
		} else {
			this->right->insert(data);
		} 
	} else if (data == this->value) {
		this->num_of_data ++;
	}
}

template <typename T>
void NodeT<T>::reinsertNode(shared_ptr<NodeT<T>> node)
{
	if (node == nullptr)
		return;
	this->insert(node->value);
	this->reinsertNode(node->left);
	this->reinsertNode(node->right);
}

template <typename T>
void NodeT<T>::remove(T data, shared_ptr<NodeT<T>> root)
{
	if (this->left != nullptr) {
		if (this->left->value == data) {
			auto tempPtr = this->left;
			this->left = nullptr;
			this->reinsertNode(tempPtr->left);
			this->reinsertNode(tempPtr->right);
			return;
		}
		this->left->remove(data, root);
	}

	if (this->right != nullptr) {
		if (this->right->value == data) {
			auto tempPtr = this->right;
			this->right = nullptr;
			this->reinsertNode(tempPtr->left);
			this->reinsertNode(tempPtr->right);
			return;
		}
		this->right->remove(data, root);
	}
}

template <typename T>
bool NodeT<T>::exist(T data) const
{
	if (this->value == data)
		return true;
	if (this->left == nullptr && this->right == nullptr)
		return false;
	return (this->left != nullptr && this->left->exist(data)) ||
		(this->right != nullptr && this->right->exist(data));
}

template <typename T>
void NodeT<T>::print(shared_ptr<NodeT<T>> p, int indent)
{
    if(p != nullptr) {
        if(p->left != nullptr) print(p->left, indent+4);
        if(p->right != nullptr) print(p->right, indent+4);
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        cout<< p->value << "\n ";
    }
}

template class NodeT<double>;
template class NodeT<string>;

template <typename T>
BinaryTreeT<T>::BinaryTreeT():
	root_(nullptr){}

template <typename T>
BinaryTreeT<T>::BinaryTreeT(T data)
{
	root_.value = data;
	root_.left = nullptr;
	root_.right = nullptr;
	root_.num_of_data = 1;
}

template <typename T>
void BinaryTreeT<T>::insert(T data)
{
	if (this->root_ == nullptr) {
		this->root = std::make_shared<NodeT<T>>(data);
	} else {
		this->root_->insert(data);
	}
}

template <typename T>
void BinaryTreeT<T>::remove(T data)
{
	if (this->root_ == nullptr)
		return;

	/// handle current node removement
	/// first, get the new root by the left node
	/// second, reinsert all the right node to the new root
	if (this->root_->value == data) {
		auto oldRoot = this->root_;
		auto newRoot = this->root_->left;
		this->root_ = newRoot;
		this->root_.reinsertNode(oldRoot->right);
		return;
	}
	/// only check for children node values, not the current node value
	this->root_->remove(data, this->root_);
}

template <typename T>
bool BinaryTreeT<T>::exist(T data) const
{
	if (this->root_ == nullptr)
		return false;
	return this->root_->exist(data);
}

}
}
}