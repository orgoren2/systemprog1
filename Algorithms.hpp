//Id-9115
//Email address- orgoren3146@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include "Graph.hpp"
using namespace std;

namespace ariel
{

    class Algorithms
    {
    private:
        Graph gr;
    
    static bool checkIsContainsCycle(size_t v, vector<bool> &visited, vector<size_t> &parent, stack<int> &cycle, vector<vector<int>> &graph);
    static void DFS(size_t v, const vector<vector<int>>& graph, vector<bool>& visited);

    public:
       
        static bool isConnected(Graph gr);
        static bool isConnectedDirected(Graph gr);
        static bool isConnectedUndirected(Graph gr);
        static string shortestPath(Graph gr, size_t start, size_t end);
        static string shortestPathWeighed(Graph gr, size_t start, size_t end);
        static string shortestPathUnweighed(Graph gr, size_t start, size_t end); 
        static string isContainsCycle(Graph gr);
        static string isBipartite(Graph gr);
        static string negativeCycle(Graph gr);
    
    };
}
#endif