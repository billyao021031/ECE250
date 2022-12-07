#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "vertex.hpp"
#include "illegal_exception.hpp"

using namespace std;

class graph
{
private:
    int vertex_num; //  number of vertices in the graph
    int edge_num; //number of edges in the graph
    vertex *vArr[23133]; //array that contains 23133 number of vertices
    vector<vertex*> heap; //heap vector that does the heapify
    vector<int> mst; //mst vector that takes in the max node

public:

    //constructor
    graph();

    //destrucotr
    ~graph();

    //inserting a pair of vertices and edges
    void insertion(int a, int b, double w);

    //print the adjacency vertices
    void print(int a);

    //delete the vertex from the graph
    void deletion(int a);

    //get the mst number based on the given index
    void getMST(int a);

    //return the number of vertices
    int getSize();

    //find if the vertices are in the graph
    bool findVertex(int id);

    //find if the edge is in the graph
    bool findCombo(int id_1, int id_2);

    //heapify function
    void heapify(int id);

    //heap building function
    void heap_builder();
};


#endif