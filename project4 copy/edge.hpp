#ifndef EDGE_HPP
#define EDGE_HPP

#include "vertex.hpp"
#include <vector>

using namespace std;

class edge
{

private:
    int id_from;
    int id_to;
    double weight;
    bool e_inserted;

    friend class graph;

public:
    edge();

    ~edge();
};

#endif