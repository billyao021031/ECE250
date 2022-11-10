#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

node::node()
{
    p_next = NULL;
    p_previous = NULL;
    link_name = "";
    link_address = "";
};

node::~node()
{
    p_next = nullptr;
    p_previous = nullptr;
    delete p_next;
    delete p_previous;
};

node::node(string u_name, string u_address)
{
    link_name = u_name;
    link_address = u_address;
};
