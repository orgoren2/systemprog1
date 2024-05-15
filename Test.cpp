#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>

using namespace doctest;
using namespace ariel;
using namespace std;

TEST_CASE("Test isConnected method") {
    // Test isConnected method with a connected graph
    Graph connectedGraph;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    connectedGraph.loadGraph(graph);
    CHECK(Algorithms::isConnected(connectedGraph));

    // Test isConnected method with a disconnected graph
    Graph disconnectedGraph;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    disconnectedGraph.loadGraph(graph1);
    CHECK_FALSE(Algorithms::isConnected(disconnectedGraph));
}
TEST_CASE("ShortestPathWeightedTest") {
    // Create a weighted graph
    Graph weightedGraph;
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    weightedGraph.loadGraph(graph);

    // Test shortest path from vertex 0 to vertex 4
    string shortestPath = Algorithms::shortestPath(weightedGraph, 0, 4);
    CHECK(shortestPath == "Shortest path from vertex 0 to vertex 4: 0->2->5->4");
}
TEST_CASE("IsBipartiteTest") {
    // Create a bipartite graph
    Graph bipartiteGraph;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    bipartiteGraph.loadGraph(graph);

    // Test if the graph is bipartite
    string bipartiteInfo = Algorithms::isBipartite(bipartiteGraph);
    CHECK(bipartiteInfo == "The graph is bipartite: A={ 0 2 }, B={ 1 3 }");

    // Create a non-bipartite graph
    Graph nonBipartiteGraph;
    vector<vector<int>> nonBipartiteGraphData = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    nonBipartiteGraph.loadGraph(nonBipartiteGraphData);

    // Test if the graph is not bipartite
    string nonBipartiteInfo = Algorithms::isBipartite(nonBipartiteGraph);
    CHECK(nonBipartiteInfo == "0");
}
TEST_CASE("NegativeCycleTest") {
    // Create a graph with a negative cycle
    Graph graphWithNegativeCycle;
    vector<vector<int>> graphData = {
        {0, -1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    graphWithNegativeCycle.loadGraph(graphData);

    // Test if the graph contains a negative cycle
    string hasNegativeCycle = Algorithms::negativeCycle(graphWithNegativeCycle);
    CHECK(hasNegativeCycle == "Graph contains negative weight cycle");

    // Create a graph without a negative cycle
    Graph graphWithoutNegativeCycle;
    vector<vector<int>> graphWithoutNegativeCycleData = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    graphWithoutNegativeCycle.loadGraph(graphWithoutNegativeCycleData);

    // Test if the graph does not contain a negative cycle
    string noNegativeCycle = Algorithms::negativeCycle(graphWithoutNegativeCycle);
    CHECK(noNegativeCycle == "Graph doesn't contain negative weight cycle");
}
