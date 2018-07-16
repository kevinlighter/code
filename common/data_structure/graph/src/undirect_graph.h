#include "graphBase.h"

#ifndef _UNDIRECTED_GRAPH_H_
#define _UNDIRECTED_GRAPH_H_

using namespace std;
namespace kevin {
namespace graph {

template <class T>
class UndirectGraphT: public GraphBaseT<T>
{
public:

	UndirectGraphT() = default;
	~UndirectGraphT() = default;

	UndirectGraphT(const int& size);

	/// @brief Add an edge
	virtual void addEdge(const T& u, const T& v);

	/// @brief Delete an edge
	virtual void deleteEdge(const T& u, const T& v);
};

using UndirectGraph = UndirectGraphT<int>;
using UndirectGraphi = UndirectGraphT<int>;
using UndirectGraphs = UndirectGraphT<string>;


}
}

#endif

