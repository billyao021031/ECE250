#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>

using namespace std;

/* When we insert a line of data into the program, we are actually inserting a relationship. Each vector needs to hold following information:
   1.An list of the vertex it is pointing to or being pointed from (vector).
   2.A list of the edge it is connecting with.
*/

class vertex
{
private:
    int id;
    bool inserted;
    double m_key;
    vector<int> adj_vertex;
    vector<double> adj_weight;
    vector<int> parent_vertex;

friend class graph;

public:
    vertex();

    ~vertex();
};

#endif