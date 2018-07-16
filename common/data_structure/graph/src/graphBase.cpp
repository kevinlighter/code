#include "graphBase.h"

namespace kevin {
namespace graph {


template <typename T>
GraphBaseT<T>::GraphBaseT(const int& size)
{
	graphMap_.reserve(size);
}

template <typename T>
void GraphBaseT<T>::printGraph() const
{
	int edgeNum = 0;
	for (auto mapIter = graphMap_.begin(); mapIter != graphMap_.end(); mapIter ++) {
		std::cout << "Node " << mapIter->first << " : ";
		edgeNum += (mapIter->second).size();
		for (auto elementIter = (mapIter->second).begin(); elementIter != (mapIter->second).end(); elementIter++) {
			std::cout << *elementIter << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Node of graph is: " << graphMap_.size() << std::endl;
	std::cout << "Num of edge in this graph is: " << edgeNum << std::endl;
	return;
}

template <typename T>
void GraphBaseT<T>::connectUwithV(const T& u, const T& v)
{
	auto iterU = graphMap_.find(u);
	if (graphMap_.count(v) <= 0)
		this->addNode(v);
	if (iterU == graphMap_.end()) {
		vector<T> vec;
		vec.reserve(100);
		vec.push_back(v);
		graphMap_.insert(pair<T, vector<T> >(u, vec));
		return;
	} else {
		(iterU->second).push_back(v);
		return;
	}
}

template <typename T>
bool GraphBaseT<T>::check_no_node(const T& u)
{
	if (graphMap_.count(u) > 0) {
		return false;
	}
	return true;
}

template <typename T>
void GraphBaseT<T>::addNode(const T& u)
{
	vector<T> vec;
	vec.reserve(100);
	graphMap_.insert(pair<T, vector<T> >(u, vec));
	return;
}

template <typename T>
void GraphBaseT<T>::deleteNode(const T& u)
{
	auto iter = graphMap_.find(u);
	/// @brief if there is no such node, simply return
	if (iter == graphMap_.end()) 
		return;

	/// @brief erase the node if it exist
	graphMap_.erase(iter);

	/// @brief delete elements connect to this node in other nodes
	for (auto nodeIter = (this->graphMap_).begin(); nodeIter != (this->graphMap_).end(); nodeIter++) {
		for (auto elementIter = (nodeIter->second).begin(); elementIter != (nodeIter->second).end(); ) {
			if (*elementIter == u) {
				elementIter = (nodeIter->second).erase(elementIter);
			} else {
				elementIter ++;
			}

		}
	}
	return;
}

template <typename T>
void GraphBaseT<T>::removeVfromU(const T& u, const T& v)
{
	auto iter = graphMap_.find(u);
	if (iter == (this->graphMap_).end())
		return;
	for (auto elementIter = (iter->second).begin(); elementIter != (iter->second).end();) {
		if (*elementIter == v) {
			elementIter = (iter->second).erase(elementIter);
			break;
		} else {
			elementIter ++;
		}
	}
	return;

}

template <typename T>
bool GraphBaseT<T>::nodeExist(const T& u)
{
	return !(this->check_no_node(u));
}

template class GraphBaseT<int>;
template class GraphBaseT<string>;

}
}