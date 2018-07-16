#include "graphBase.h"

#ifndef _DIRECTED_GRAPH_H_
#define _DIRECTED_GRAPH_H_

using namespace std;
namespace kevin {
namespace graph {

template <class T>
class DirectGraphT: public GraphBaseT<T>
{
public:

	DirectGraphT() = default;
	~DirectGraphT() = default;

	DirectGraphT(const int& size);

	/// @brief Add an edge
	virtual void addEdge(const T& u, const T& v);

	/// @brief Delete an edge: if u is pointing to v, delete this connection
	virtual void deleteEdge(const T& u, const T& v);
};

using DirectGraph = DirectGraphT<int>;
using DirectGraphi = DirectGraphT<int>;
using DirectGraphs = DirectGraphT<string>;


}
}

#endif

