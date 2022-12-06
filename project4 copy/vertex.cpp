#include "vertex.hpp"

vertex::vertex(){
    v_inserted = false;
    vAdj.resize(0);
    vEdge.resize(0);
}

vertex::~vertex(){
    vAdj.clear();
    vEdge.clear();
}
