#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>

#ifndef _DECISION_TREE_H_
#define _DECISION_TREE_H_

using namespace std;

namespace decision_tree{

struct Node {
	// Index number of node to specify the location of tree
	int index{-1};
	// set of children nodes
	set<int> children;
	// feature name 
	string feature;
	// attribute value
	string attrValue;
	// if the node is a leaf node
	bool is_leaf{0};
	// label
	string label;
};

class DecisionTree {

public:
	DecisionTree() = default;
	~DecisionTree() = default;

	// This constructor storage the feature list
	DecisionTree(const vector<string>& feature_list,
				 const vector<vector<string>>& data_table,
				 const vector<string>& data_label);

	// This function choose the spilt feature based on info gain
	string choose_feature(const set<int>& data_index);

	// This function train the tree
	void implement_grow_tree();

	// return the table
	inline vector<vector<string>> table_data() {
		return data_table_;
	}

	// return the feature_list
	inline map<string, int> feature_map() {
		return feature_map_;
	}

	// return the feature_list
	inline map<int, string> feature_map_inverse() {
		return feature_map_inverse_;
	}

	// return the label_list
	inline vector<string> table_label() {
		return data_label_;
	}

public:
	// This function storage the feature list into a map with int label
	void storage_feature_map(const vector<string>& feature_list);

	// This function storage the data in the tree
	void storage_data(const vector<vector<string>>& data_table);

	// This function storage the label
	void storage_label(const vector<string>& data_label);

	// This function storage the feature map with all the possible value in a set
	void storage_fea_val_map(const map<int, string>& feature_map_inverse,
				 		     const vector<vector<string>>& data_table);

	// This function calculate the information gain of a specific feature
	double cal_info_gain(const set<int>& data_index, const int& feature_num);

	// This function grow the tree based on recursion and input data index
	void grow_tree(const set<int>& data_index, const int& parent_node_index);

	// This function get label base on the data index, using the maximum probability
	string get_label(const set<int>& data_index);

	// This function choose the data and return the set of index based on the
	// chosen feature
	// set<int> data_index: data to spilt from
	// string feature_name: feature to spilt with
	// return map of data_index of specific feature value
	map<string, set<int> > choose_data(const set<int>& data_index, const int& feature_num);

	// Help function to get the feature name based on the feature number
	inline string feature_converter(const int& num) {
		return feature_map_inverse_[num];
	}

	// Help function to get the feature num based on the feature name
	inline int feature_converter(const string& str) {
		return feature_map_[str];
	}

	// Help function to get tree model
	inline vector<Node> tree(){
		return tree_;
	}

private:
	vector<Node> tree_;
	map<string, int> feature_map_;
	map<int, string> feature_map_inverse_;
	map<int, set<string> > feature_map_value_;
	vector<vector<string>> data_table_;
	vector<string> data_label_;
	int current_node_num_{-1};

};

}

// Define print out function
template <class T>
ostream& operator<<(ostream& s, const vector<T>& vec) {
	for (auto& t : vec) {
		s << t << " ";
	}
	s << std::endl;
	return s;
}

template <class T>
ostream& operator<<(ostream& s, const vector<vector<T> >& vec) {
	s << "matrix is: " << std::endl;
	for (auto& t : vec) {
		for (auto& i : t) {
			s << i << " ";
		}
		s << std::endl;
	}
	return s;
}

template <class T>
ostream& operator<<(ostream& s, const set<T>& set) {
	s << "set is: ";
	for (auto& t : set) {
		s << t << " ";
	}
	s << std::endl;
	return s;
}

template <class T, class Q>
ostream& operator<<(ostream& s, const map<T,Q>& map) {
	s << "map is: ";
	for (auto& t : map) {
		s << t.first << " : " << t.second << std::endl;
	}
	return s;
}

ostream& operator<<(ostream& s, const decision_tree::Node& node);

#endif
