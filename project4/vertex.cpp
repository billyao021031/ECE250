#include "vertex.hpp"

vertex::vertex(){
    m_key = -1;
    id = 0;
    inserted = false;
    adj_vertex.resize(0);
    adj_weight.resize(0);
    parent_vertex.resize(0);
}

vertex::~vertex(){
    adj_vertex.clear();
    adj_weight.clear();
    parent_vertex.clear();
}
