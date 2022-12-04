#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include "vertex.hpp"

using namespace std;

class graph
{
private:
    int vertex_num;

public:

    graph();

    ~graph();

    void insertion(int a, int b, double w);

    void print(int a);

    void deletion(int a);

    void getMST(int a);

    int getSize();
};


#endif