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
    
        Graph() {
            this->isDirected=false;
            bool isWeighed =false;
            this->numOfEdges=0;
            this->numOfVertices=0; 
        }

        void loadGraph(vector<vector<int>> &gr);
        void printGraph() const;
        
        // inline methods
        bool getIsDirected() const
        { 
            return this->isDirected;
        }
        bool getIsWeighed() const
        { 
            return this->isWeighed;
        }
        int getNumOfVertices() const
        { 
            return this->numOfVertices;
        }
        //For testing countNumOfEdges
        int getNumOfEdges() const
        { 
            return this->numOfEdges;
        }
        vector<vector<int>> getGraph() const
        { 
            return this->graph;
        }
    };
}
#endif