//Id-9115
//Email address- orgoren3146@gmail.com
#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

/** The function gets vector and loads it to the graph.
 * It also initalizes the class fields
 */

void Graph::loadGraph(vector<vector<int>> &gr)
{
    if(gr.empty() || gr.size()==0 || gr.size()!=gr[0].size()){
         throw invalid_argument("Invalid matrix");
    }

    this->graph = gr; 
    this->numOfVertices = gr.size(); 

    size_t isD = 0;
    size_t isW = 0; 
    for (size_t i = 0; i < gr.size(); i++)
    {
        for (size_t z = 0; z < gr.size(); z++)
        {
            if(i==z && gr[i][z]!=0){
                throw invalid_argument("Invalid matrix");
            }
            if (gr[i][z] != gr[z][i])
            {
                isD++;
            }
            if (gr[i][z] > 1)
            {
                isW++;
            }
        }
    }
    if (isD != 0)
    {
        this->isDirected = true;
    }
    if (isW != 0)
    {
        this->isWeighed = true;
    }

    this->numOfEdges = countNumOfEdges(gr);
}

// Side function for the print method
int Graph::countNumOfEdges(vector<vector<int>> &gr)
{

    int countEdges = 0;
    for (size_t i = 0; i < gr.size(); i++)
    {
        for (size_t z = 0; z < gr.size(); z++)
        {
            if (gr[i][z] != 0)
            {
                countEdges++;
            }
        }
    }
    if (this->isDirected == 1)
    {
        return countEdges;
    }
    return countEdges / 2;
}

// The function prints the graph's number of vertices and edges
void Graph::printGraph() const
{
     
    cout << "Graph with " << this->numOfVertices << " vertices and " << this->numOfEdges << " edges" << endl;
}
