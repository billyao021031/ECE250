#include "graph.hpp"

#include <iostream>
#include <vector>

using namespace std;

graph::graph()
{
    vertex_num = 0;
    edge_num = 0;
}


graph::~graph()
{
}


bool graph::findVertex(int id)
{
    if (vArr[id - 1].inserted == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool graph::findCombo(int id_1, int id_2)
{
    for (int i = 0; i < vArr[id_1 - 1].adj_vertex.size(); i++)
    {
        if (vArr[id_1 - 1].adj_vertex.at(i) == id_2)
        {
            return true;
        }
    }

    return false;
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

    if (findCombo(id_1, id_2) == false)
    {

        vArr[id_1 - 1].adj_vertex.push_back(id_2);
        vArr[id_1 - 1].adj_weight.push_back(weight);
        vArr[id_2 - 1].parent_vertex.push_back(id_1);

        if (vArr[id_1 - 1].inserted == false)
        {
            vArr[id_1 - 1].inserted = true;
            vertex_num += 1;
        }

        if (vArr[id_2 - 1].inserted == false)
        {
            vArr[id_2 - 1].inserted = true;
            vertex_num += 1;
        }

        edge_num += 1;

        cout << "success" << endl;
    }
    else
    {
        cout << "failure" << endl;
    }
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

    for (int i = 0; i < vArr[id - 1].adj_vertex.size(); i++)
    {
        cout << vArr[id - 1].adj_vertex.at(i) << " ";
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

    if (findVertex(id) == false || vertex_num == 0)
    {
        cout << "failure" << endl;
    }
    else
    {
        vArr[id - 1].adj_vertex.clear();
        vArr[id - 1].adj_vertex.resize(0);
        vArr[id - 1].adj_weight.clear();
        vArr[id - 1].adj_weight.resize(0);
        vArr[id - 1].inserted = false;

        for(int i = 0; i < vArr[id - 1].parent_vertex.size(); i++){
            int parent_id = vArr[id - 1].parent_vertex.at(i);
            for(int j = 0; j < vArr[parent_id - 1].adj_vertex.size(); j++){
                if(vArr[parent_id - 1].adj_vertex.at(j) == id){
                    vector<int>::iterator it;
                    it = vArr[parent_id - 1].adj_vertex.begin();
                    vArr[parent_id - 1].adj_vertex.erase(it + j);
                }
            }
        }

        cout << "success" << endl;
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