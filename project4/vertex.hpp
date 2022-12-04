#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>

using namespace std;

class vertex
{
private:
    double edge;
    int id;

public:

    vertex();

    ~vertex();

    friend class graph;
};

#endif