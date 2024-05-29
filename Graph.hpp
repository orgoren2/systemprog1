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

    public:
    
        Graph() {
            this->isDirected=false;
            bool isWeighed =false;
            this->numOfEdges=0;
            this->numOfVertices=0;
          
        }

        void loadGraph(vector<vector<int>> gr);
        int countNumOfEdges(vector<vector<int>> gr);
        void printGraph();
        

        // inline methods
        bool getIsDirected()
        { 
            return this->isDirected;
        }
        bool getIsWeighed()
        { 
            return this->isWeighed;
        }
        int getNumOfVertices()
        { 
            return this->numOfVertices;
        }
        vector<vector<int>> getGraph()
        { 
            return this->graph;
        }
    };
}
#endif