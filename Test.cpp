//Id-9115
//Email address- orgoren3146@gmail.com

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

TEST_CASE("Test isConnected method on unweighed undirected graph") {
    // Test isConnected method with a connected graph
    Graph connectedGraph1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    connectedGraph1.loadGraph(graph);
    CHECK(Algorithms::isConnected(connectedGraph1));
}

TEST_CASE("Test isConnected method on unweighed undirected graph") {
    // Test isConnected method with a disconnected graph
    Graph disconnectedGraph1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}
    };
    disconnectedGraph1.loadGraph(graph1);
    CHECK_FALSE(Algorithms::isConnected(disconnectedGraph1));
}

TEST_CASE("Test isConnected method on unweighed directed graph") {
    // Test isConnected method with a connected graph
    Graph connectedGraph2;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0}
    };
    connectedGraph2.loadGraph(graph);
    CHECK(Algorithms::isConnected(connectedGraph2));
}
TEST_CASE("Test isConnected method on unweighed directed graph") {
    // Test isConnected method with a disconnected graph
    Graph disconnectedGraph2;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };
    disconnectedGraph2.loadGraph(graph1);
    CHECK_FALSE(Algorithms::isConnected(disconnectedGraph2));
}

TEST_CASE("Test isConnected method on weighed undirected graph") {
    // Test isConnected method with a connected graph
    Graph connectedGraph3;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 4},
        {0, 4, 0}
    };
    connectedGraph3.loadGraph(graph);
    CHECK(Algorithms::isConnected(connectedGraph3));
}

TEST_CASE("Test isConnected method on weighed undirected graph") {
    // Test isConnected method with a disconnected graph
    Graph disconnectedGraph3;
    std::vector<std::vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 0},
        {0, 0, 0}
    };
    disconnectedGraph3.loadGraph(graph1);
    CHECK_FALSE(Algorithms::isConnected(disconnectedGraph3));
}

TEST_CASE("Test isConnected method on weighed directed graph") {
    // Test isConnected method with a connected graph
    Graph connectedGraph4;
    std::vector<std::vector<int>> graph = {
        {0, 2, 0},
        {0, 0, 3},
        {10, 5, 0}
    };
    connectedGraph4.loadGraph(graph);
    CHECK(Algorithms::isConnected(connectedGraph4));
}

TEST_CASE("Test isConnected method on weighed directed graph") {
    // Test isConnected method with a disconnected graph
    Graph disconnectedGraph4;
    std::vector<std::vector<int>> graph1 = {
        {0, 10, 0},
        {0, 0, 0},
        {7, 0, 0}
    };
    disconnectedGraph4.loadGraph(graph1);
    CHECK_FALSE(Algorithms::isConnected(disconnectedGraph4));
}


TEST_CASE("Shortest Path Weighted Undirected Test") {
    // Create a weighted graph
    Graph weightedGraph1;
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
    weightedGraph1.loadGraph(graph);

    // Test shortest path from vertex 0 to vertex 4
    string shortestPath = Algorithms::shortestPath(weightedGraph1, 0, 4);
    CHECK(shortestPath == "Shortest path from vertex 0 to vertex 4: 0->7->6->5->4");
}


TEST_CASE("Shortest Path Weighted directed Test") {
    // Create a weighted graph
    Graph weightedGraph2;
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {3, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 6, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 0, 0, 0, 0, 6, 7, 0}
    };
    weightedGraph2.loadGraph(graph);

    // Test shortest path from vertex 0 to vertex 4
    string shortestPath = Algorithms::shortestPath(weightedGraph2, 0, 4);
    CHECK(shortestPath == "Shortest path from vertex 0 to vertex 4: 0->7->6->5->4");
}


TEST_CASE("Shortest Path unweighted Undirected Test") {
    // Create a weighted graph
    Graph weightedGraph3;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };
    weightedGraph3.loadGraph(graph);

    // Test shortest path from vertex 0 to vertex 4
    string shortestPath = Algorithms::shortestPath(weightedGraph3, 0, 3);
    CHECK(shortestPath == "Shortest path from vertex 0 to vertex 3: 0->1->3");
}

TEST_CASE("Shortest Path unweighted directed Test") {
    // Create a weighted graph
    Graph weightedGraph4;
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };
    weightedGraph4.loadGraph(graph);

    // Test shortest path from vertex 0 to vertex 4
    string shortestPath = Algorithms::shortestPath(weightedGraph4, 0, 3);
    CHECK(shortestPath == "Shortest path from vertex 0 to vertex 3: 0->1->2->3");
}


TEST_CASE("Is Bipartite Test unweighed undirected graph") {
    // Create a bipartite graph
    Graph bipartiteGraph1;
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    bipartiteGraph1.loadGraph(graph);

    // Test if the graph is bipartite
    string bipartiteInfo = Algorithms::isBipartite(bipartiteGraph1);
    CHECK(bipartiteInfo == "The graph is bipartite: A={ 0 2 }, B={ 1 3 }");
}

TEST_CASE("Is Bipartite Test unweighed directed graph") {
    // Create a non-bipartite graph
    Graph nonBipartiteGraph1;
    vector<vector<int>> nonBipartiteGraphData = {
        {0, 1, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 0}
    };
    nonBipartiteGraph1.loadGraph(nonBipartiteGraphData);

    // Test if the graph is not bipartite
    string nonBipartiteInfo = Algorithms::isBipartite(nonBipartiteGraph1);
    CHECK(nonBipartiteInfo == "0");
}

TEST_CASE("Is Bipartite Test weighed undirected graph") {
    // Create a bipartite graph
    Graph bipartiteGraph2;
    vector<vector<int>> graph = {
        {0, 2, 0, 11},
        {2, 0, 7, 0},
        {0, 7, 0, 4},
        {11, 0, 4, 0}
    };
    bipartiteGraph2.loadGraph(graph);

    // Test if the graph is bipartite
    string bipartiteInfo = Algorithms::isBipartite(bipartiteGraph2);
    CHECK(bipartiteInfo == "The graph is bipartite: A={ 0 2 }, B={ 1 3 }");
}

TEST_CASE("Is Bipartite Test weighed directed graph") {
    // Create a non-bipartite graph
    Graph nonBipartiteGraph2;
    vector<vector<int>> nonBipartiteGraphData = {
        {0, 2, 0, 7},
        {0, 0, 0, 5},
        {0, 0, 0, 3},
        {1, 10, 15, 0}
    };
    nonBipartiteGraph2.loadGraph(nonBipartiteGraphData);

    // Test if the graph is not bipartite
    string nonBipartiteInfo = Algorithms::isBipartite(nonBipartiteGraph2);
    CHECK(nonBipartiteInfo == "0");
}


TEST_CASE("Test is contains cycle method on unweighed undirected graph") {
    // Test isConnected method with a connected graph
    Graph cycleGraph1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    cycleGraph1.loadGraph(graph);
    string cycleGraph=Algorithms::isContainsCycle(cycleGraph1); 
    CHECK(cycleGraph=="The cycle is: 0->1->0");
}

TEST_CASE("Test is contains cycle method on unweighed directed graph") {
    // Test isConnected method with a connected graph
    Graph cycleGraph2;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0}
    };
    cycleGraph2.loadGraph(graph);
    string cycleGraph=Algorithms::isContainsCycle(cycleGraph2); 
    CHECK(cycleGraph=="The cycle is: 0->1->2->0");
}

TEST_CASE("Test is contains cycle method on unweighed directed graph") {
    // Test isConnected method with a connected graph
    Graph noncycleGraph1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}
    };
    noncycleGraph1.loadGraph(graph);
    string cycleGraph=Algorithms::isContainsCycle(noncycleGraph1); 
    CHECK(cycleGraph== "0");
}

TEST_CASE("Test is contains cycle method on weighed undirected graph") {
    // Test isConnected method with a connected graph
    Graph cycleGraph3;
    std::vector<std::vector<int>> graph = {
        {0, 12, 0},
        {12, 0, 2},
        {0, 2, 0}
    };
    cycleGraph3.loadGraph(graph);
    string cycleGraph=Algorithms::isContainsCycle(cycleGraph3); 
    CHECK(cycleGraph=="The cycle is: 0->1->0");
}


TEST_CASE("Negative Cycle Test weighed directed graph") {
    // Create a graph with a negative cycle
    Graph graphWithNegativeCycle1;
    vector<vector<int>> graphData = {
        {0, 2, 5},
        {-3, 0, 7},
        {2, 4, 0}
    };
    graphWithNegativeCycle1.loadGraph(graphData);

    // Test if the graph contains a negative cycle
    string hasNegativeCycle = Algorithms::negativeCycle(graphWithNegativeCycle1);
    CHECK(hasNegativeCycle == "Graph contains negative weight cycle");
}


TEST_CASE("Negative Cycle Test weighed directed graph") {
    // Create a graph with a negative cycle
    Graph graphWithNegativeCycle2;
    vector<vector<int>> graphData = {
        {0, -10, 5},
        {3, 0, 7},
        {2, 4, 0}
    };
    graphWithNegativeCycle2.loadGraph(graphData);

    // Test if the graph contains a negative cycle
    string hasNegativeCycle = Algorithms::negativeCycle(graphWithNegativeCycle2);
    CHECK(hasNegativeCycle == "Graph contains negative weight cycle");
}

TEST_CASE("Negative Cycle Test undirected unweighed graph") {
    // Create a graph without a negative cycle
    Graph graphWithoutNegativeCycle1;
    vector<vector<int>> graphWithoutNegativeCycleData = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    graphWithoutNegativeCycle1.loadGraph(graphWithoutNegativeCycleData);

    // Test if the graph does not contain a negative cycle
    string noNegativeCycle = Algorithms::negativeCycle(graphWithoutNegativeCycle1);
    CHECK(noNegativeCycle == "Graph doesn't contains negative weight cycle");
}
