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

namespace common::tree::KDTree {

template <class T>
struct NodeT {
	T value;

	// int cur_index{-1}
	// int left_index{-1};
	// int right_index{-1};
	NodeT<T>* left_node;
	NodeT<T>* right_node;
	int spilt_axis{-1};
};

template <class T>
class KDTreeT {

public:

	KDTreeT() = default;
	~KDTreeT() = default;

	// Define the dimension of KDTreeT
	KDTreeT(const int& dimension);

	// Insert a large set of data into the KDTreeT
	void insert(const vector<vector<T>>& data);

	// Insert a point data into the KDTreeT
	void insert(const vector<T>& data);

	// Delete a point data from the KDTreeT
	void delete(const vector<T>& data);


public:
	// Choose the axis of spilt based on depth
	int chooseAxis(const int& depth);

	// Get median point of a specific dimension based on some data points
	// By selecting randomly chosen fix number of sorted data
	int medianPointIndex(const vector<vector<T>>& data, const int& dth);

	// grow KDTreeT
	void grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, 
				   const int& depth, const int& parent_node_number);

	// get the spilt data indexes from the left and right 
	void spilt_indexes(const vector<vector<T>>& data, unordered_set<int>& left_indexes,
						unordered_set<int>& right_indexes, const int& dth, const int& median_index);
private:

	int dimension_{-1};
	vector<common::tree::KDTree::NodeT<T>> tree_; 
	int num_for_sorting_{10};
};

using KDTreed = KDTreeT<double>;
using KDTrees = KDTreeT<std::string>;

}

#endif