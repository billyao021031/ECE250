#include "node.hpp"
#include <string>


node::node()
{
    //initialize node member variables
    terminal = false;
    character = "";
    int i = 0;
    while (i < 26)
    {
        children[i] = NULL;
        i++;
    }
}

node::~node()
{
    //destruct every node's children
    int i = 0;
    while (i < 26)
    {
        delete this->children[i];

        this->children[i] = NULL;

        i++;
    }
}

int node::numOfChildren(node *p_count)
{
    //return the number of children from a given node
    int num = 0;

    int j = 0;
    while (j < 26)
    {
        if (p_count->children[j] != NULL)
        {
            num++;
        }
        j++;
    }

    return num;
}