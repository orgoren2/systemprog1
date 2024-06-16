//Id-9115
//Email address- orgoren3146@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
using namespace std;

namespace ariel
{
    class Graph
    {

    private:
        vector<vector<int>> graph;
        bool isDirected;
        bool isWeighed ;
        int numOfVertices;
        int numOfEdges;
        int countNumOfEdges(vector<vector<int>> &gr);
    
    public:
    
        Graph();
        void loadGraph(vector<vector<int>> &gr);
        void printGraph() const;
        bool getIsDirected() const;
        bool getIsWeighed() const;
        int getNumOfVertices() const;
        int getNumOfEdges() const;
        vector<vector<int>> getGraph() const;
    };
}
#endif