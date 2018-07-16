#include "graphBase.h"
#include <queue>


#ifndef _GRAPH_BFS_H_
#define _GRAPH_BFS_H_

using namespace std;

namespace kevin {
namespace graph {

template <class T>
class BFST {
public:

	BFST() = default;
	~BFST() = default;

	/// @brief constructor with graph pointer
	BFST(GraphBaseT<T> * graph_ptr);

	/// @brief exploration of bfs in the graph with a start point
	unordered_set<T> explore(const T& start);

	/// @brief calculate the components of graph
	unordered_map<int, unordered_set<T> > calculate_components();

	/// @brief calculate the shortest path between two nodes
	int calculate_min_path(const T& first, const T& second);

private:
	/// @brief pointer to the graph
	GraphBaseT<T>* graphPtr_;

};



template <class T>
ostream& operator<<(ostream& s, const unordered_map<int, unordered_set<T> >& map){
	s << "explored components are: " << std::endl;
	for (auto& t : map) {
		s << t.first << " : ";
		for (auto& ti : t.second) {
			s << ti << " ";
		}
		s << endl;
	}
	return s; 
}

using BFS = BFST<int>;
using BFSi = BFST<int>;
using BFSs = BFST<string>;
}
}

#endif