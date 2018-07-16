#include "decision_tree.h"

using namespace std;

namespace decision_tree{


DecisionTree::DecisionTree(const vector<string>& feature_list,
				 const vector<vector<string>>& data_table,
				 const vector<string>& data_label):
	current_node_num_(0)
{
	this->storage_feature_map(feature_list);
	this->storage_data(data_table);
	this->storage_label(data_label);
}

void DecisionTree::storage_feature_map(const vector<string>& feature_list)
{
	feature_map_.clear();
	feature_map_inverse_.clear();
	for (int i=0;i<feature_list.size();i++) {
		feature_map_.insert(pair<string, int>(feature_list[i], i));
		feature_map_inverse_.insert(pair<int, string>(i, feature_list[i]));
	}
}

void DecisionTree::storage_data(const vector<vector<string>>& data_table)
{
	data_table_.clear();
	data_table_ = data_table;
}

void DecisionTree::storage_label(const vector<string>& data_label)
{
	data_label_.clear();
	data_label_ = data_label;
}

void DecisionTree::storage_fea_val_map(const map<int, string>& feature_map_inverse,
				 					   const vector<vector<string>>& data_table)
{
	feature_map_value_.clear();
	for (auto it = feature_map_inverse.begin(); it != feature_map_inverse.end(); it++) {
		set<string> new_set;
		feature_map_value_.insert(pair<int, set<string> >(it->first, new_set));
	}

	for (auto& vec : data_table) {
		for (int i=0;i<vec.size();i++) {
			auto it = feature_map_value_[i].count(vec[i]);
			if (!it) {
				feature_map_value_[i].insert(vec[i]);
			}
		}
	}
}

double DecisionTree::cal_info_gain(const set<int>& data_index, const int& feature_num)
{
	map<string, int> probability_map;
	for (auto& s : data_index) {
		auto it = probability_map.find(data_table_[s][feature_num]);

		if (it == probability_map.end()) {
			probability_map.insert(pair<string, int>(data_table_[s][feature_num], 1));
		} else {
			it->second ++;
		}
	}

	// Use the map to calculate entropy
	double sum = 0.0;
	for (auto it = probability_map.begin(); it != probability_map.end(); it++) {
		double probability = static_cast<double>(it->second) / data_index.size();
		sum += -probability * log2(probability);
	}

	return sum;
}

string DecisionTree::choose_feature(const set<int>& data_index)
{
	double max = 0.0;
	int feature_num = -1;
	for (auto it = feature_map_.begin(); it != feature_map_.end(); it++) {
		double temp = this->cal_info_gain(data_index, it->second);
		std::cout << "temp: " << temp << " " << it->second << std::endl;
		if (temp > max) {
			max = temp;
			feature_num = it->second;
		}
		std::cout << "temp" << std::endl;
	}

	if (feature_num == -1) {
		return "EndSpilt";
	}

	return this->feature_converter(feature_num);
}

map<string, set<int> > DecisionTree::choose_data(const set<int>& data_index, 
												 const int& feature_num)
{
	map<string, set<int> > spilt_map;
	for (auto& t : data_index) {
		auto it = spilt_map.find(data_table_[t][feature_num]);
		if (it == spilt_map.end()) {
			set<int> new_set;
			new_set.insert(t);
			spilt_map.insert(pair<string, set<int> >(data_table_[t][feature_num], new_set));
		} else {
			it->second.insert(t);
		}
	}
	return spilt_map;
}

void DecisionTree::grow_tree(const set<int>& data_index, const int& cur_node_index)
{
	string chosen_feature = this->choose_feature(data_index);
	int feature_node_num = current_node_num_;

	if (cur_node_index == 0) {
		Node new_feature_node;

		new_feature_node.feature = chosen_feature;
		new_feature_node.attrValue = "NaN";
		new_feature_node.index = feature_node_num;

		tree_.push_back(new_feature_node);
		current_node_num_ ++;

	} else {
		tree_[cur_node_index].feature = chosen_feature;
	}

	// Decide end case
	if (chosen_feature == "EndSpilt") {
		std::cout << "end here" << std::endl;
		tree_[cur_node_index].is_leaf = 1;
		//tree_[cur_node_index].label = this->get_label(data_index);
		tree_[cur_node_index].label = "!!!!!!!!";
		return;
	} else {
		tree_[cur_node_index].label = "NaN";
	}
	
	// Get the spilt data
	map<string, set<int> > children_data_map = 
				this->choose_data(data_index, this->feature_converter(chosen_feature));

	// Grow branches
	for (auto& t : children_data_map) {
		// Create value node
		Node new_value_node;
		new_value_node.feature = "NaN";
		new_value_node.attrValue = t.first;
		new_value_node.index = current_node_num_;
		
		tree_.push_back(new_value_node);
		tree_[cur_node_index].children.insert(current_node_num_);
		current_node_num_ ++;

		this->grow_tree(t.second, current_node_num_-1);
	}
}

void DecisionTree::implement_grow_tree()
{
	set<int> data_index;
	for (int i=0; i<data_table_.size(); i++) {
		data_index.insert(i);
	}
	this->grow_tree(data_index, 0);
}

string DecisionTree::get_label(const set<int>& data_index)
{
	map<string, int> label_probability_map;
	for (auto& t : data_index)
	{
		auto it = label_probability_map.find(data_label_[t]);
		if (it == label_probability_map.end()) {
			label_probability_map.insert(pair<string, int>(data_label_[t], 1));
		} else {
			it->second ++;
		}
	}

	int max = 0;
	string max_label = "";
	for (auto& s : label_probability_map)
	{
		if (s.second > max) {
			max_label = s.first;
		}
	}
	return max_label;
}

// void DecisionTree::grow_tree(const set<int>& data_index, const int& parent_node_index)
// {
// 	// Create feature node
// 	Node new_feature_node;
// 	// Give node index number
// 	// Store the feature node number
// 	int feature_node_num = current_node_num_;
// 	new_feature_node.index = feature_node_num;
// 	// std::cout << "tree size: " << (bool)(parent_node_index<tree_.size()) << std::endl;

// 	if (parent_node_index > -1 && parent_node_index < tree_.size()) {
// 		std::cout << "here" << std::endl;
// 		tree_[parent_node_index].children.insert(feature_node_num);
// 	} else {
// 		std::cout << "a" << std::endl;
// 		// try {
// 		// 	throw parent_node_index;
// 		// } catch (int e) {
// 		// 	std::cout << "Exception occured. No. " << e << std::endl;
// 		// }
// 	}

	
// 	// Get the chosen feature based on input data index
// 	string chosen_feature = this->choose_feature(data_index);
	
// 	new_feature_node.feature = chosen_feature;
// 	new_feature_node.attrValue = "NaN";

// 	tree_.push_back(new_feature_node);
// 	current_node_num_ ++;

// 	// Decide end case
// 	if (chosen_feature == "EndSpilt") {
// 		std::cout << "end here" << std::endl;
// 		tree_[feature_node_num].is_leaf = 1;
// 		return;
// 	}
	
// 	// Get the spilt data
// 	map<string, set<int> > children_data_map = 
// 				this->choose_data(data_index, this->feature_converter(chosen_feature));
	
// 	std::cout << "Chosen feature: " << chosen_feature << std::endl << " node num: " << feature_node_num << std::endl;
// 	std::cout << "cur spilt: "  << std::endl << children_data_map;

// 	// Grow branches
// 	for (auto& t : children_data_map) {
// 		// Create value node
// 		Node new_value_node;
// 		new_value_node.feature = "NaN";
// 		new_value_node.attrValue = t.first;
// 		new_value_node.index = current_node_num_;
		
// 		tree_.push_back(new_value_node);
// 		tree_[feature_node_num].children.insert(current_node_num_);
// 		current_node_num_ ++;

// 		this->grow_tree(t.second, current_node_num_-1);
// 	}
// }

}


ostream& operator<<(ostream& s, const decision_tree::Node& node) {
	s << "Node is: " << std::endl;
	s << "      index: " << node.index << std::endl;
	s << "      children: " << node.children;
	s << "      feature: " << node.feature << std::endl;
	s << "      attrVal: " << node.attrValue << std::endl;
	s << "      is_leaf: " << node.is_leaf << std::endl;
	s << "      label: " << node.label << std::endl;
	return s;
}