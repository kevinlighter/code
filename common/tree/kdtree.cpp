#include "kdtree.h"

using namespace std;

namespace common::tree::kdtree {


KDTree::KDTree(const int& dimension):
	dimension_(dimension)
{
	tree_.clear();
	srand (time(NULL));
}

int KDTree::chooseAxis(const int& depth)
{
	return depth % dimension_;
}

void KDTree::grow_tree(const vector<vector<T>>& data, const unordered_set<int>& data_index, int& depth)
{
	int chosen_axis = this->chooseAxis(depth);
	int median_point_index = this->medianPointIndex(data, chosen_axis);

}

int KDTree::medianPointIndex(const vector<vector<T>>& data, const int& dth)
{	
	int shuffle_size = num_for_sorting_;
	if (data.size() < num_for_sorting_)
		shuffle_size = data.size();

	// fill a vector with 0 to n-1
	std::vector<int> vec(shuffle_size) ; 
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


}