#ifndef TRIE_HPP
#define TRIE_HPP

#include "node.hpp"
#include <string>

using namespace std;

class trie
{
    private:
        int trieSize; // store the current size of trie
        node *root; //root node

    public:

        //constructor
        trie();

        //destructor
        ~trie();

        //insert a new word into trie
        void insertion(string input);

        //search if a word exits in trie
        bool searching(string input);

        //erase a word from the trie
        void erase(string input);

        //erase recursive function
        void erase_h(node *erase, string input, int pos);

        //print all the words in the trie
        void print();

        //print recursive function
        void print_h(node *print, string targetWord);

        //spellcheck a word based on the trie
        void spellcheck(string input);

        //spellcheck recursive function
        void spellcheck_h(node *p_spell, string input, int pos);

        //check if the trie is empty
        bool empty();

        //clear all the words from the trie
        void clear();

        //clear recursive function 
        void clear_h(node *p_clear);
        
        //return the current size of the tree.
        void countSize();
};

#endif