#include "node.hpp"
#include <string>

node::node()
{
    terminal = false;
    pushed = false;
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
    int i = 0;
    while (i < 26)
    {
        this->children[i] = nullptr;
        delete this->children[i];
        i++;
    }
}

int node::numOfChildren(node *p_count)
{
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