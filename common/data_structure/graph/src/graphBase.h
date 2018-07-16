#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#ifndef _GRAPH_BASE_H_
#define _GRAPH_BASE_H_

using namespace std;
namespace kevin {
namespace graph {

/// @brief graph representation of base class
template <class T>
class GraphBaseT {

public:

	typedef typename unordered_map<T, vector<T> >::iterator iterator;

	GraphBaseT() = default;
	~GraphBaseT() = default;

	GraphBaseT(const int& size);

	/// @brief Add an edge
	virtual void addEdge(const T& u, const T& v) = 0;

	/// @brief Delete an edge
	virtual void deleteEdge(const T& u, const T& v) = 0;

	/// @brief Add a node
	void addNode(const T& n);

	/// @brief Delete a node completely
	void deleteNode(const T& u);

	/// @brief help function list
	void printGraph() const;

	/// @brief check if a node exist
	bool nodeExist(const T& u);

	/// @brief get number of nodes in the graph
	inline int size() const {
		return graphMap_.size();
	}

	/// @brief get number of edge in a specific node
	inline int size_of_node(const T& u) const {
		return graphMap_.find(u)->second.size();
	}

	/// @brief get the vector of edges that this node connect
	inline vector<T> edge_of_node(const T& u) const {
		return graphMap_.find(u)->second;
	}

	/// @brief return the map of the graph
	inline auto graph() const {
		return graphMap_;
	}

	/// @brief return the iterator with node name
	inline auto find(const T& u) const {
		return graphMap_.find(u);
	}

	/// @brief return the end iterator flag of graph
	inline auto end() const {
		return graphMap_.end();
	}

	inline auto count(const T& u) const {
		return graphMap_.count(u);
	}

	inline auto begin() const {
		return graphMap_.begin();
	}

	// inline auto extract(const T& u) const {
	// 	return graphMap_.extract(u);
	// }

	// inline void insert(const auto& u) {
	// 	graphMap_.insert(u);
	// }

	inline void clear() {
		graphMap_.clear();
	}

protected:
	unordered_map<T, vector<T> >  graphMap_;

protected:

	/// @brief connection building u->v
	void connectUwithV(const T& u, const T& v);
	
	/// @brief Remove edge v from node u
	void removeVfromU(const T& u, const T& v);

	/// @brief bool check_no_node(const T& u);
	bool check_no_node(const T& u);

};

template <class T>
ostream& operator<<(ostream& s, const vector<T>& vec){
	s << "edge is: ";
	for (auto& t : vec) {
		s << t << " ";
	}
	return s; 
}

template <class T>
ostream& operator<<(ostream& s, const unordered_set<T>& set){
	s << "explored nodes are: " << std::endl;
	for (auto& t : set) {
		s << t << " ";
	}
	return s; 
}

template <class T, class R>
ostream& operator<<(ostream& s, const unordered_map<T, R>& map){
	s << "maps are: " << std::endl;
	for (auto& t : map) {
		s << t.first << " : " << t.second << " " << std::endl;
	}
	return s; 
}

using GraphBase = GraphBaseT<int>;
using GraphBasei = GraphBaseT<int>;
using GraphBases = GraphBaseT<string>;

}
}

#endif