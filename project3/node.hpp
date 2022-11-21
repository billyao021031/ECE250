#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std;

// int const numOfCharacter = 26;

class node
{
private:
    node *children[26];
    bool terminal;
    string character;
    bool pushed;

    friend class trie;

public:
    node();

    ~node();

    int numOfChildren(node *p_count);
};

#endif