#include "breath_first_search.h"

using namespace std;
namespace kevin {
namespace graph {

template <typename T>
BFST<T>::BFST(GraphBaseT<T> * graph_ptr):
	graphPtr_(graph_ptr)
{
}

template <typename T>
unordered_set<T> BFST<T>::explore(const T& start)
{
	if (graphPtr_->count(start) <= 0) {
		return unordered_set<T>();
	}

	queue<T> container;
	unordered_set<T> explored;
	explored.reserve(graphPtr_->size());
	container.push(start);
	explored.insert(start);

	while (!container.empty()) {
		T pop  = container.front();
		container.pop();
		auto iter= graphPtr_->find(pop);
		for (auto& t : iter->second) {
			if (!explored.count(t)) {
				explored.insert(t);
				container.push(t);
			}
		}
	}
	return explored;
}


template <typename T>
unordered_map<int, unordered_set<T> > BFST<T>::calculate_components()
{
	unordered_map<int, unordered_set<T> > components;
	int numOfComp = 0;
	unordered_set<T> mainSet;
	mainSet.reserve(graphPtr_->size());	
	for (auto it = graphPtr_->begin();it != graphPtr_->end(); it++) {
		T t = it->first;
		if (mainSet.count(t)) {
			continue;
		} else {
			unordered_set<T> curSet = this->explore(t);
			mainSet.insert(curSet.begin(), curSet.end());
			components.insert(pair<int, unordered_set<T> >(numOfComp, curSet));
			numOfComp ++;
		}
	}
	return components;
}


template <typename T>
int BFST<T>::calculate_min_path(const T& first, const T& second)
{
	/// @brief maintain a map: min_path.first = nodeName; min_path.second = distance
	unordered_map<T, int> min_path;
	min_path.insert(pair<T, int>(first, 0));


	if (graphPtr_->count(first) <= 0 || graphPtr_->count(second) <= 0) {
		return 10e6;
	}

	queue<T> container;
	unordered_set<T> explored;
	explored.reserve(100);
	container.push(first);
	explored.insert(first);

	while (!container.empty()) {
		T pop  = container.front();
		container.pop();
		auto iter= graphPtr_->find(pop);
		for (auto& t : iter->second) {
			if (!explored.count(t)) {
				int dist = (min_path.find(pop))->second;
				min_path.insert(pair<T, int>(t, dist+1));
				explored.insert(t);
				container.push(t);
			}
		}
	}
	return (min_path.find(second))->second;


}

template class BFST<int>;
template class BFST<string>;

}
}