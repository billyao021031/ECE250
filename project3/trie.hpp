#ifndef TRIE_HPP
#define TRIE_HPP

#include "node.hpp"
#include <string>

using namespace std;

class trie
{
    private:
        int trieSize;
        node *root;

    public:
        trie();
        ~trie();

        void trieload();

        void insertion(string input);

        bool searching(string input);

        void erase(string input);

        void print();

        void spellcheck(string input);

        bool empty();

        void clear();

        void countSize();
};

#endif