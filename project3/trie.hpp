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

        void erase_h(node *p, string input, int pos);

        void print();

        void print_h(node *p, string targetWord);

        void spellcheck(string input);

        void spellcheck_h(node *p_spell, string input, int pos);

        bool empty();

        void clear();

        void clear_h(node *p_clear);

        void countSize();
};

#endif