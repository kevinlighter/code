#include "graphBase.h"
#include "undirect_graph.h"
#include "direct_graph.h"
#include "load_graph.h"
#include "breath_first_search.h"
#include "depth_first_search.h"

using namespace std;
using namespace kevin::graph;

int main() {

	// UndirectGraphT<int> graph = loadUDGraph<int>("kargerMinCut.txt", 1000000);

	// BFST<int> bfs(&graph);
	// DFST<int> dfs(&graph);

	// //auto c = bfs.calculate_components();

	// //std::cout << c << std::endl;

	// //std::cout << bfs.calculate_min_path(2,15) << std::endl;

	//std::cout << dfs.explore(2) << std::endl;

	//std::cout << dfs.topological_sort() << std::endl;

	// bfs.explore(1);

	// bfs.printExploration();



	//graph.printGraph();

	//std::cout << graph.size_of_node(1) << std::endl;

	//vector<int> vec = graph.edge_of_node(1);
	//std::cout << vec << std::endl;

	//std::cout << graph.find(1)->second << std::endl;



	DirectGraphT<int> graph2(100);

	// graph2.addNode(1);
	// graph2.addNode(1);
	// graph2.addNode(2);
	// graph2.addNode(3);

	// graph2.addNode(4);

	// graph2.addEdge(1,2);
	// graph2.addEdge(3,4);
	// graph2.addEdge(3,5);
	// graph2.addEdge(3,6);
	// graph2.addEdge(3,7);
	// graph2.addEdge(3,7);
	// graph2.addEdge(3,7);
	// graph2.addEdge(3,7);
	// graph2.addEdge(3,7);
	// graph2.addEdge(3,7);
	// graph2.addEdge(13,17);

	graph2.addEdge(7,1);
	graph2.addEdge(1,4);
	graph2.addEdge(4,7);
	graph2.addEdge(9,7);
	graph2.addEdge(6,9);
	graph2.addEdge(9,3);
	graph2.addEdge(3,6);
	graph2.addEdge(8,6);
	graph2.addEdge(8,5);
	graph2.addEdge(5,2);
    graph2.addEdge(2,8);
	//graph2.addEdge(11,1);

	graph2.printGraph();

	DirectGraphT<int> graph3;

	DFST<int>::reverse(&graph2, &graph3);

	graph3.printGraph();


	DFST<int>::scc(&graph2);

	// graph2.insert(pair<int, vector<int> >(1, vector<int>()));



	// BFST<int> bfs(&graph2);

	// DFST<int> dfs(&graph2);

	// std::cout << dfs.explore(1) << std::endl;

	//std::cout << "cyclic or not: " << DFST<int>::cyclic(&graph2, 1) << std::endl;

	// auto d = dfs.exploreImp(1);

	// std::cout << d << std::endl;


	// auto c = bfs.calculate_components();

	// std::cout << c << std::endl;

	 //auto a = bfs.explore(1);

	// std::cout << a << std::endl;

	// auto a = bfs.explore(1);

	// std::cout << a << std::endl;

	// std::cout << a << std::endl;

	// a = bfs.explore(15);

	// std::cout << a << std::endl;


	//bfs.printExploration();

	// //graph2.deleteNode(3);
	// graph2.deleteEdge(3,7);
	// graph2.deleteEdge(13,17);



	//graph2.printGraph();
	return 0;
}