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

        void insertion(string word);

        void searching(string word);

        void erase(string word);

        void print();

        void spellcheck(string word);

        bool empty();

        void clear();

        void countSize();
};

#endif