#include "direct_graph.h"

namespace kevin {
namespace graph {

template <typename T>
DirectGraphT<T>::DirectGraphT(const int& size):
	GraphBaseT<T>(size)
{
}

template <typename T>
void DirectGraphT<T>::addEdge(const T& u, const T& v) {
	this->connectUwithV(u,v);
}

template <typename T>
void DirectGraphT<T>::deleteEdge(const T& u, const T& v) {
	this->removeVfromU(u,v);
}

template class DirectGraphT<int>;
template class DirectGraphT<string>;

}
}

