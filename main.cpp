#include <iostream>
#include <vector>

#include "Graph.h"
#include "UnitTest.h"
int main() {
	int bfsVertex;
	int a;
	int b;
	char answer='z';
	//testGraph.print();
	/*
	static test code 
	std::vector<Edge>edgy = { {1,2},{1,3},{2,4},{2,5},{4,5},{5,6},{3,6} };
	Graph testGraph(6,edgy);
	BFS(testGraph,1);
	printPath(testGraph,1);
	*/

	Graph testGraph = createGraph();
	testGraph.print();
	
	do {
		std::cout << "\nEnter root vertex for BFS tree: ";
		std::cin >> bfsVertex;
		BFS(testGraph, bfsVertex);
		std::cout << "Choose Starting vertex: ";
		std::cin >> a;
		std::cout << "Choose Destination vertex: ";
		std::cin >> b;
		BFS(testGraph, a);
		std::cout << "\nShortest distance between point " << a << " and point " << b << ": " << std::endl;
		printPath(testGraph, a, b);
		std::cout << "\n Do you want to continue using the same graph?(y/n): ";
		while (answer != 'y' && answer != 'n') {
			std::cin >> answer;
		}
		if (answer == 'n') {
			break;
		}
	} while (true);


	//runAllTests();
	return 0;
}