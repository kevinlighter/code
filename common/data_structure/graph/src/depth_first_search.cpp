#include "depth_first_search.h"

using namespace std;
namespace kevin {
namespace graph {

template <typename T>
DFST<T>::DFST(GraphBaseT<T> * const graph_ptr):
	graphPtr_(graph_ptr)
{
}


template <typename T>
void DFST<T>::explore_recursive(const T& start, unordered_set<T>& mainSet)
{
	auto it = graphPtr_->find(start);
	if (it == graphPtr_->end()) 
		return;

	mainSet.insert(start);
	for (auto& vecIt : it->second) {
		if (!mainSet.count(vecIt)) {
			this->explore_recursive(vecIt, mainSet);
		}
	}
	return;
}


template <typename T>
void DFST<T>::explore_recursive(const T& start, unordered_set<T>& mainSet, 
								unordered_map<T, int>& mainMap, int& label)
{
	auto it = graphPtr_->find(start);
	if (it == graphPtr_->end()) 
		return;

	mainSet.insert(start);
	for (auto& vecIt : it->second) {
		if (!mainSet.count(vecIt)) {
			this->explore_recursive(vecIt, mainSet, mainMap, label);
		}
	}
	mainMap.insert(pair<T, int>(start, label));
	label --;
	return;
}

template <typename T>
unordered_set<T> DFST<T>::explore(const T& start)
{
	// unordered_set<T> mainSet;
	// this->explore_recursive(start, mainSet);
	// return mainSet;

	if (graphPtr_->count(start) <= 0) {
		return unordered_set<T>();
	}

	stack<T> container;
	unordered_set<T> explored;
	explored.reserve(graphPtr_->size());
	container.push(start);
	explored.insert(start);

	while (!container.empty()) {
		T pop  = container.top();
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
unordered_map<T, int> DFST<T>::topological_sort()
{
	int label = graphPtr_->size();
	unordered_map<T, int> mainMap;
	mainMap.reserve(label);

	unordered_set<T> mainSet;

	auto it = graphPtr_->begin();
	for (;it != graphPtr_->end();it++) {
		if (!mainMap.count(it->first)) {
			this->explore_recursive(it->first, mainSet, mainMap, label);
		}
	}
	return mainMap;
}

template <typename T>
bool DFST<T>::cyclic(GraphBaseT<T> * const graph_ptr, const T& start)
{
	if (graph_ptr->count(start) <= 0)
		return false;

	unordered_map<T, unordered_set<T> > predecessor;
	stack<T> container;
	unordered_set<T> explored;
	explored.reserve(graph_ptr->size());
	container.push(start);
	explored.insert(start);

	predecessor.insert(pair<T, unordered_set<T> >(start, unordered_set<T>()));

	while (!container.empty()) {
		T pop  = container.top();
		container.pop();
		auto iter= graph_ptr->find(pop);

		// find the mother node iter->first
		T mother = iter->first;
		auto motherIt = predecessor.find(mother);

		for (auto& t : iter->second) {

			unordered_set<T> T_insert = motherIt->second;

			// Check if previous passing nodes (storage in predecessor->second set) have t or not
			if (T_insert.count(t) > 0) {
				return true;
			}

			T_insert.insert(mother);

			auto preIt = predecessor.find(t);
			if (preIt == predecessor.end()) {
				predecessor.insert(pair<T, unordered_set<T> >(t, T_insert));
			} else {
				// merge two set
				unordered_set<T> T_before = preIt->second;
				T_insert.insert(T_before.begin(), T_before.end());
				preIt->second = T_insert;
			}
			
			if (!explored.count(t)) {
				explored.insert(t);
				container.push(t);
			}
		}
	}
	return false;
}

template <typename T>
void DFST<T>::reverse(GraphBaseT<T> * const graph_ptr, GraphBaseT<T> * reverse_graph_ptr)
{
	reverse_graph_ptr->clear();
	reverse_graph_ptr->graph().reserve(graph_ptr->size());
	auto iter = graph_ptr->begin();
	for (;iter != graph_ptr->end(); iter++) {
		for (auto& t : iter->second) {
			reverse_graph_ptr->addEdge(t, iter->first);
		}
	}
}

template <typename T>
unordered_map<T, unordered_set<T> > DFST<T>::scc(GraphBaseT<T> * graph_ptr)
{
	DirectGraphT<T> reverse_graph(graph_ptr->size());
	DFST<T>::reverse(graph_ptr, &reverse_graph);

	int finishTime = 0;

	unordered_set<T> explored;
	unordered_map<int, T> magicOrder;
	unordered_map<T, int> magicOrderSecond;

	/// @brief doing first looping
	auto nodeIt = graph_ptr->begin();
	for (;nodeIt != graph_ptr->end(); nodeIt ++) {
		if (!explored.count(nodeIt->first)) {
			DFST<T>::kosaraju_first_loop(&reverse_graph, nodeIt->first, explored, magicOrder, magicOrderSecond, finishTime);
		}
	}

	/// @brief doing second looping
	explored.clear();
	unordered_map<T, unordered_set<T> > sccMap;
	unordered_set<int> explored_int;
	
	DFST<T>::kosaraju_second_loop(graph_ptr, magicOrder, magicOrderSecond, 
		finishTime, explored_int, sccMap, finishTime);

	return sccMap;

}

template <typename T>
void DFST<T>::kosaraju_first_loop(GraphBaseT<T> * const graph_ptr, const T& start, 
							   unordered_set<T>& explored, unordered_map<int, T>& magicOrder,
							   unordered_map<T, int>& magicOrderSecond, int& finishTime)
{
	auto it = graph_ptr->find(start);
	if (it == graph_ptr->end()) 
		return;

	explored.insert(start);
	std::cout << "put :" << start << " in explored" << std::endl;

	for (auto& vecIt : it->second) {
		std::cout << "loop :" << vecIt << std::endl;
		if (!explored.count(vecIt)) {
			
			DFST<T>::kosaraju_first_loop(graph_ptr, vecIt, explored, 
				magicOrder, magicOrderSecond, finishTime);
		}
	}
	finishTime ++;
	magicOrder.insert(pair<int, T>(finishTime, start));
	magicOrderSecond.insert(pair<T, int>(start, finishTime));
	
	std::cout << "finish time: " << finishTime << " node:" << start << std::endl; 
	return;
}

template <typename T>
void DFST<T>::kosaraju_second_loop(GraphBaseT<T> * const graph_ptr, const unordered_map<int, T>& magicOrder,
								const unordered_map<T, int>& magicOrderSecond, const int& start_int, 
								unordered_set<int>& explored_int, unordered_map<T, unordered_set<T> >& sccMap,
								int& descent_order)
{
	auto curNode = graph_ptr->find(magicOrder.find(start_int)->second);
	if (curNode == graph_ptr->end()) 
		return;

	explored_int.insert(start_int);

	for (auto& vecIt : curNode->second) {
		int order = magicOrderSecond.find(vecIt)->second;
		if (!explored_int.count(order)) {
			
			DFST<T>::kosaraju_second_loop(graph_ptr, magicOrder, magicOrderSecond, 
							order, explored_int, sccMap, descent_order);
		} else {
			descent_order --;
		}
	} 
	return;
}



template class DFST<int>;
template class DFST<string>;
}
}