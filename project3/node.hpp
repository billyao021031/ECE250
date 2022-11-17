#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std;

// int const numOfCharacter = 26;

class node
{
private:
    node *children[26];
    node *parent;
    bool terminal;
    std::string character;

    friend class trie;

public:
    node();

    ~node();
};

#endif