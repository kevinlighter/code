#include "btree.h"
#include <iostream>

using namespace common::tree::BTree;

template <typename T>
NodeT<T>* test_btree_constructor()
{
	Noded node1(5);
	Nodes node2("abc");
	return &node2;
}

template <typename T>
void test_btree_print(std::shared_ptr<NodeT<T>> nodePtr)
{
	NodeT<T>::print(nodePtr);
}


int main() {
	Noded node1(5);
	Nodes node2("abc");
	

	node1.insert(10);
	node1.insert(18);
	node1.insert(7);
	node1.insert(-1);
	node1.insert(-10);
	node1.insert(6);
	node1.insert(4);
	node1.insert(2);
	node1.insert(9);
	node1.insert(13);
	node1.insert(3);

	test_btree_print<double>(std::make_shared<Noded>(node1));

	//print<double>(std::make_shared<Noded>(node1));


	return 0;

}