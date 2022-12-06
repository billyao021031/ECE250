#include "graph.hpp"

#include <iostream>
#include <vector>

using namespace std;

graph::graph()
{
    vertex_num = 0;
    edge_num = 0;
    edgeArr.resize(0);
}

graph::~graph()
{
    edgeArr.clear();
}

void graph::insertion(int id_1, int id_2, double weight)
{
    bool insertion;

    try
    {
        if (id_1 > 23133 || id_1 < 1 || id_2 > 23133 || id_2 < 1 || weight < 0.0 || weight > 1.0)
        {
            throw illegal_exception();
        }
    }
    catch (illegal_exception alert)
    {
        cout << alert.msg() << endl;
        return;
    }

    edge insertList;

    insertList.id_from = id_1;
    insertList.id_to = id_2;
    insertList.weight = weight;
    insertList.e_inserted = true;
    edgeArr.push_back(insertList);

    if(vArr[id_1 - 1].v_inserted == false){
        vertex_num += 1;
        vArr[id_1 - 1].v_inserted= true;
    }

    if(vArr[id_2 - 1].v_inserted == false){
        vertex_num += 1;
        vArr[id_2 - 1].v_inserted= true;
    }

    vArr[id_1 - 1].vAdj.push_back(id_2);
    vArr[id_2 - 1].vAdj.push_back(id_1);

    vArr[id_1 - 1].vEdge.push_back(edge_num);
    vArr[id_2 - 1].vEdge.push_back(edge_num);

    edge_num+=1;

    cout << "success" << endl;

}

void graph::print(int id)
{
    try
    {
        if (id > 23133 || id < 1)
        {
            throw illegal_exception();
        }
    }
    catch (illegal_exception alert)
    {
        cout << alert.msg() << endl;
        return;
    }

    for(int i = 0; i < vArr[id - 1].vAdj.size(); i++){
        int edgeCheck = vArr[id-1].vEdge[i];
        int adjCheck = vArr[id-1].vAdj[i];
        if((edgeArr[edgeCheck].id_from == id) && (vArr[adjCheck-1].v_inserted == true) && (edgeArr[edgeCheck].e_inserted == true)){
            cout << adjCheck << " ";
        }
    }
    cout << endl;
}

void graph::deletion(int id)
{
    try
    {
        if (id > 23133 || id < 1)
        {
            throw illegal_exception();
        }
    }
    catch (illegal_exception alert)
    {
        cout << alert.msg() << endl;
        return;
    }
}

void graph::getMST(int id)
{
}

int graph::getSize()
{
    cout << "number of vertices is " << vertex_num << endl;
    return vertex_num;
}