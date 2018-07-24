#include "KDTreeT.h"

using namespace std;

namespace common::tree::KDTree {


KDTreeT<T>::KDTreeT(const int& dimension):
	dimension_(dimension)
{
	tree_.clear();
	srand (time(NULL));
}

int KDTreeT::chooseAxis(const int& depth)
{
	return depth % dimension_;
}

template <typename T>
void KDTreeT<T>::grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, 
						   const int& depth, const int& parent_node_number)
{
	int chosen_axis = this->chooseAxis(depth);
	int median_point_index = this->medianPointIndex(data, chosen_axis);


	unordered_set<int> left_indexes;
	unordered_set<int> right_indexes;
	this->spilt_indexes(data, left_indexes, right_indexes, chosen_axis, median_point_index);

	/// Grow tree in the left node
	this->grow_tree(data, left_indexes, depth+1);
	/// Grow tree in the right node
	this->grow_tree(data, right_indexes, depth+1);
}

template <typename T>
int KDTreeT<T>::medianPointIndex(const vector<vector<T>>& data, const int& dth)
{	
	int shuffle_size = num_for_sorting_;
	if (data.size() < num_for_sorting_)
		shuffle_size = data.size();

	// fill a vector with 0 to n-1
	std::vector<int> vec(data.size()) ; 
	std::iota (std::begin(vec), std::end(vec), 0); 

	// shuffle the vector randomly
	std::random_shuffle(vec.begin(), vec.end());

	// Create pre-sort vector
	vector<T> pre_sort(shuffle_size);
	unordered_map<T, int> map;
	for (int i=0;i<shuffle_size;i++) {
		pre_sort[i] = data[vec[i]][dth];
		map.insert(pair<T, int>(data[vec[i]][dth] ,vec[i]));
	}
	// sorting
	std::sort(pre_sort.begin(), pre_sort.end());
	// data index
	return map[ pre_sort[shuffle_size / 2] ];
}

template <typename T>
void KDTreeT<T>::spilt_indexes(const vector<vector<T>>& data, unordered_set<int>& left_indexes,
						unordered_set<int>& right_indexes, const int& axis, const int& median_index)
{
	T median_feature = data[median_index][axis];
	for (int i=0;i<data.size();i++) {
		if (data[i][axis] < median_feature) {
			left_indexes.insert(i);
		} else {
			right_indexes.insert(i);
		}
	}
}


template class KDTreeT<double>;
template class KDTreeT<std::string>;


}