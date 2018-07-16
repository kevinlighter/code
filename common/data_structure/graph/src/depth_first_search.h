#include "graphBase.h"
#include "direct_graph.h"
#include <stack>

#ifndef _GRAPH_DFS_H_
#define _GRAPH_DFS_H_

using namespace std;

namespace kevin {
namespace graph {

template <class T>
class DFST
{
public:
	DFST() = default;
	~DFST() = default;

	/// @brief constructor with graph pointer
	DFST(GraphBaseT<T> * const graph_ptr);

	/// @brief exploration of bfs in the graph with a start point
	unordered_set<T> explore(const T& start);

	/// @brief topological sort
	unordered_map<T, int> topological_sort();

	/// @brief exploration of bfs in the graph with a start point
	void explore_recursive(const T& start, unordered_set<T>& mainSet);

	/// @brief exploration of bfs in the graph with a start point
	void explore_recursive(const T& start, unordered_set<T>& mainSet, 
							unordered_map<T, int>& mainMap, int& label);

	/// @brief decide this graph if it's cyclic or not
	static bool cyclic(GraphBaseT<T> * const graph_ptr, const T& start);

	/// @brief reverse a directed graph
	static void reverse(GraphBaseT<T> * const graph_ptr, GraphBaseT<T> * reverse_graph_ptr);

	/// @brief kosaraju's algorithm for calculating SCCs
	static unordered_map<T, unordered_set<T> > scc(GraphBaseT<T> * graph_ptr);

	/// @brief kosaraju's recursive dfs
	static void kosaraju_first_loop(GraphBaseT<T> * const graph_ptr, const T& start, 
							   unordered_set<T>& explored, unordered_map<int, T>& magicOrder,
							   unordered_map<T, int>& magicOrderSecond, int& finishTime);

	static void kosaraju_second_loop(GraphBaseT<T> * const graph_ptr, const unordered_map<int, T>& magicOrder,
								const unordered_map<T, int>& magicOrderSecond, const int& start_int, 
								unordered_set<int>& explored, unordered_map<T, unordered_set<T> >& sccMap,
								int& descent_order);
private:
	/// @brief pointer to the graph
	GraphBaseT<T>* const graphPtr_;
};


using DFS = DFST<int>;
using DFSi = DFST<int>;
using DFSs = DFST<string>;

}
}

#endif