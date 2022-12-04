#include "graph.hpp"
#include "illegal_exception.hpp"

#include <iostream>

using namespace std;

graph::graph()
{
    vertex_num = 0;
}

graph::~graph()
{
}

void graph::insertion(int id_1, int id_2, double weight)
{
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
    return 0;
}