#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
struct Node {
	int vertex;
	Node* next = nullptr;
	Node* pi= nullptr;//previous
	std::string color = "white";
	int d=-1;//distance to s
};
struct Edge{
	int a;
	int b;
};
class Graph {
	public:
		Graph();
		Graph(int ,std::vector<Edge>);
		~Graph();
		void print();
		friend void BFS(Graph&, int);
		friend void printPath(Graph&,int,int);
		int getNumVert();
		std::vector<Node*> getAdjList();
	private:
		int numVert;//number of vertices 
		std::vector<Node*> adjList;//list of nodes

};
Node* traverseLinkedList(Node*&);
void printLinkedList(Node*);
Graph createGraph();

#endif