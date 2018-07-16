#include <algorithm>
#include <vector>
#include <unordered_set>
#include <time.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unordered_map>

#ifndef _COMMON_TREE_KDTREE_H_
#define _COMMON_TREE_KDTREE_H_

using namespace std;

namespace common::tree::kdtree {

template <class T>
struct Node {
	vector<T> value;
	int cur_index{-1}
	int left_index{-1};
	int right_index{-1};
	int spilt_axis{-1};
};

template <class T>
class KDTree {

public:

	KDTree() = default;
	~KDTree() = default;

	// Define the dimension of kdtree
	KDTree(const int& dimension);

	// Insert a large set of data into the kdtree
	void insert(const vector<vector<T>>& data);

	// Insert a point data into the kdtree
	void insert(const vector<T>& data);

	// Delete a point data from the kdtree
	void delete(const vector<T>& data);


public:
	// Choose the axis of spilt based on depth
	int chooseAxis(const int& depth);

	// Get median point of a specific dimension based on some data points
	// By selecting randomly chosen fix number of sorted data
	int medianPointIndex(const vector<vector<T>>& data, const int& dth);

	// grow kdtree
	void grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, int& depth);

private:

	int dimension_{-1};
	vector<common::tree::kdtree::Node> tree_; 
	int num_for_sorting_{10};
};

}

#endif