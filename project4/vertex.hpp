#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

using namespace std;

class vertex
{
private:
    int id; //id of the vertex
    bool inserted; //boolean flag
    double m_key; //mst key
    vector<int> adj_vertex; //adjacency lsit
    vector<double> adj_weight; //adjacency list weight
    vector<int> parent_vertex; //parent vertices

friend class graph;

public:

    //costructor
    vertex();

    //destructor
    ~vertex();
};

#endif