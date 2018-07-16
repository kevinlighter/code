#include "undirect_graph.h"

namespace kevin {
namespace graph {

template <typename T>
UndirectGraphT<T>::UndirectGraphT(const int& size):
	GraphBaseT<T>(size)
{
}

template <typename T>
void UndirectGraphT<T>::addEdge(const T& u, const T& v) {
	this->connectUwithV(u,v);
	this->connectUwithV(v,u);
}

template <typename T>
void UndirectGraphT<T>::deleteEdge(const T& u, const T& v) {
	this->removeVfromU(u,v);
	this->removeVfromU(v,u);
}

template class UndirectGraphT<int>;
template class UndirectGraphT<string>;

}
}

