//Id-9115
//Email address- orgoren3146@gmail.com
#include "Graph.hpp"
#include <iostream>
using namespace std;
using namespace ariel;


void Graph::loadGraph(vector<vector<int>> gr)
{
    this->graph = gr; 
    this->numOfVertices = gr.size(); 

    size_t isD = 0;
    size_t isW = 0; 
    for (size_t i = 0; i < gr.size(); i++)
    {
        for (size_t z = 0; z < gr.size(); z++)
        {
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

int Graph::countNumOfEdges(vector<vector<int>> gr)
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

void Graph::printGraph()
{
     
    cout << "Graph with " << this->numOfVertices << " vertices and " << this->numOfEdges << " edges" << endl;
}
