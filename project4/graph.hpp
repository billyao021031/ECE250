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
    vector<vertex*> heap;
    vector<int> mst;

public:

    graph();

    ~graph();

    void insertion(int a, int b, double w);

    void print(int a);

    void deletion(int a);

    void getMST(int a);

    int getSize();

    bool findVertex(int id);

    bool findCombo(int id_1, int id_2);

    void heapify(int id);

    void heap_builder();
};


#endif