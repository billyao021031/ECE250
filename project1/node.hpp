#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class node
{
private:
    node *p_next; //points to the next node 
    node *p_previous; //points to the previous node
    string link_name; //store the link name of input URL
    string link_address; //store the link address of input URL

    friend class deque;

public:
    node();
    //constructor

    ~node();
    //destructor

    node(string u_name, string u_address);
    /* When a URL is being input into the node,
    it separately stores the URL name and URL address. 
    */
};

#endif 