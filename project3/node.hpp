#ifndef NODE_HPP
#define NODE_HPP

#include <string>

using namespace std;

class node
{
    private:
        node *children;
        node *parent;
        bool terminal;
        int const numOfCharacter = 26;
        std::string letter;

    friend class trie;

    public:
        node();
        ~node();

};

#endif