#include "kdtree.h"

using namespace std;

namespace common {

namespace tree {

namespace KDTree {

template <typename T>
KDTreeT<T>::KDTreeT(const int& dimension):
	dimension_(dimension)
{
	srand (time(NULL));
}

template <typename T>
int KDTreeT<T>::chooseAxis(const int& depth)
{
	return depth % dimension_;
}

template <typename T>
NodeT<T>* KDTreeT<T>::grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, const int& depth)
{
	int chosen_axis = this->chooseAxis(depth);
	int median_point_index = this->medianPointIndex(data, chosen_axis);


	unordered_set<int> left_indexes;
	unordered_set<int> right_indexes;
	this->spilt_indexes(data, left_indexes, right_indexes, chosen_axis, median_point_index);

	NodeT<T> new_node;
	new_node.value = data[median_point_index][chosen_axis];
	new_node.spilt_axis = chosen_axis;

	/// if either of the set is not empty, iterator on the specific side
	if (!left_indexes.empty())
		new_node.left_node = this->grow_tree(data, left_indexes, depth+1);

	if (!right_indexes.empty())
		new_node.right_node = this->grow_tree(data, right_indexes, depth+1);

	return &new_node;
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
}
}