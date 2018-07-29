#include <algorithm>
#include <vector>
#include <unordered_set>
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unordered_map>
#include <string>

#ifndef _COMMON_TREE_KDTreeT_H_
#define _COMMON_TREE_KDTreeT_H_

using namespace std;

namespace common {

namespace tree {

namespace KDTree {

template <class T>
struct NodeT {
	T value;
	NodeT<T>* left_node{nullptr};
	NodeT<T>* right_node{nullptr};
	int spilt_axis{-1};
};

using Noded = NodeT<double>;
using Nodes = NodeT<std::string>;

template <class T>
class KDTreeT {

public:

	KDTreeT() = default;
	~KDTreeT() = default;

	// Define the dimension of KDTreeT
	KDTreeT(const int& dimension);

	// Insert a large set of data into the KDTreeT
	// void insert(const vector<vector<T>>& data);

	// // Insert a point data into the KDTreeT
	// void insert(const vector<T>& data);

	// // Delete a point data from the KDTreeT
	// void delete(const vector<T>& data);


public:
	// Choose the axis of spilt based on depth
	int chooseAxis(const int& depth);

	// Get median point of a specific dimension based on some data points
	// By selecting randomly chosen fix number of sorted data
	int medianPointIndex(const vector<vector<T>>& data, const int& dth);

	// grow KDTreeT
	NodeT<T>* grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, const int& depth);

	// get the spilt data indexes from the left and right 
	void spilt_indexes(const vector<vector<T>>& data, unordered_set<int>& left_indexes,
						unordered_set<int>& right_indexes, const int& dth, const int& median_index);
private:

	int dimension_{-1};
	//vector<common::tree::KDTree::NodeT<T>> tree_; 
	common::tree::KDTree::NodeT<T> tree_node_;
	int num_for_sorting_{10};
};

using KDTreed = KDTreeT<double>;
using KDTrees = KDTreeT<std::string>;

}
}
}

#endif