#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std; 

class node
{
private:
    node *children[26]; //a node can have no more than 26 children
    bool terminal; //flag whether the character is a stop
    string character; // character stored at the node

    friend class trie;

public:
    //constructor   
    node();

    //destructor
    ~node();

    //return the number of children of a node
    int numOfChildren(node *p_count);
};


class illegal_exception  : public  std:: exception{

};

#endif