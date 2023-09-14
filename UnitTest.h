#ifndef UNITTEST_H
#define UNITTEST_H
#include <iostream>
#include <sstream>
#include <cassert>
#include "Graph.h"

bool testGraphConstructor()
{
    Graph graph;
    return graph.getNumVert() == -1 && graph.getAdjList().empty();
}

// Unit test for the Graph constructor with parameters
bool testGraphConstructorWithParameters()
{
    std::vector<Edge> edges = { {1, 2}, {2, 3} };
    Graph graph(3, edges);
    if (graph.getNumVert() != 3 || graph.getAdjList().size() != 3) {
        return false;
    }

    for (int i = 0; i < 3; ++i)
    {
        Node* node = graph.getAdjList().at(i);
        if (node->vertex != i+1 ) {
            return false;
        }
    }
    return true;
}

// Unit test for the print method
bool testPrint()
{
    // Create a graph for testing
    std::vector<Edge> edges = { {1, 2}, {2, 3} };
    Graph graph(3, edges);

    // Redirect cout to a stringstream for capturing output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Call the print method
    graph.print();

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Compare the captured output with the expected output
    std::string expectedOutput = "1 2 \n2 1 3 \n3 2 \n";
    return buffer.str() == expectedOutput;
}

// Unit test for the BFS method
bool testBFS()
{
    // Create a graph for testing
    std::vector<Edge> edges = { {1, 2}, {2, 3} };
    Graph graph(3, edges);

    // Redirect cout to a stringstream for capturing output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Call the BFS method
    BFS(graph, 1);

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Compare the captured output with the expected output
    std::string expectedOutput = "1 \n2 \n3 \n";
    return buffer.str() == expectedOutput;
}

// Unit test for the printPath method
bool testPrintPath()
{
    // Create a graph for testing
    std::vector<Edge> edges = { {1, 2}, {2, 3} };
    Graph graph(3, edges);

    // Redirect cout to a stringstream for capturing output
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Call the printPath method
    BFS(graph, 1);
    printPath(graph, 1, 3);

    // Restore cout
    std::cout.rdbuf(oldCout);

    // Compare the captured output with the expected output
    std::string expectedOutput = "1 \n2 \n3 \n1->2->3";
    std::cout << buffer.str();
    return buffer.str() == expectedOutput;
}

void runAllTests() {
    bool result;

    // Test Graph constructor without parameters
    result = testGraphConstructor();
    std::cout << "Graph constructor without parameters: " << (result ? "Passed" : "Failed") << std::endl;

    // Test Graph constructor with parameters
    result = testGraphConstructorWithParameters();
    std::cout << "Graph constructor with parameters: " << (result ? "Passed" : "Failed") << std::endl;

    // Test print method
    result = testPrint();
    std::cout << "Graph print method: " << (result ? "Passed" : "Failed") << std::endl;

    // Test BFS method
    result = testBFS();
    std::cout << "BFS method: " << (result ? "Passed" : "Failed") << std::endl;

    // Test printPath method
    result = testPrintPath();
    std::cout << "PrintPath method: " << (result ? "Passed" : "Failed") << std::endl;
}
#endif // !UNITTEST_H

