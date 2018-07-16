#include "direct_graph.h"
#include "undirect_graph.h"
#include <sstream>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;

namespace kevin {
namespace graph {

template <class T>
DirectGraphT<T> loadDGraph(const string& filename, const int& size)
{
	ifstream graph_file;
	string a = "";
	graph_file.open(filename);
	DirectGraphT<T> graph(size);

	while (getline(graph_file, a)) {
		istringstream buffer(a);
		vector<T> line{(istream_iterator<int>(buffer)), istream_iterator<int>()};
		graph.addEdge(line[0], line[1]);
	}
	return graph;
}

template <class T>
UndirectGraphT<T> loadUDGraph(const string& filename, const int& size)
{
	ifstream graph_file;
	string a = "";
	graph_file.open(filename);
	UndirectGraphT<T> graph(size);

	while (getline(graph_file, a)) {
		istringstream buffer(a);
		vector<T> line{(istream_iterator<int>(buffer)), istream_iterator<int>()};
		for (int i=1;i<line.size();i++) {
			graph.addEdge(line[0], line[i]);
		}
	}
	return graph;
}

}
}

