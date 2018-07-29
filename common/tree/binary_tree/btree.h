#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#ifndef _COMMON_TREE_KDTreeT_H_
#define _COMMON_TREE_KDTreeT_H_

using namespace std;

namespace common {
namespace tree {
namespace BTree {

template <class T>
struct NodeT {

	T value;
	shared_ptr<NodeT<T>> left;
	shared_ptr<NodeT<T>> right;
	int num_of_data;

    NodeT(T data);
	void insert(T data);

	/// data here is the wanted data, 
	/// root here is the position used for reinsert
	/// remove all the duplicates
	void remove(T data, shared_ptr<NodeT<T>> root);
	bool exist(T data) const;

	void reinsertNode(shared_ptr<NodeT<T>> node);

	static void print(shared_ptr<NodeT<T>> p, int indent=0);
};

template <class T>
class BinaryTreeT {
public:

	BinaryTreeT();

	BinaryTreeT(T data);

	void insert(T data);

	void remove(T data);

	bool exist(T data) const;

	inline auto tree() const {
		return root_;
	}

private:

	shared_ptr<NodeT<T>> root_;


};



using Noded = NodeT<double>;
using Nodes = NodeT<string>;

}
}
}

#endif