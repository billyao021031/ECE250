#include "trie.hpp"
#include <string>
#include <iostream>

using namespace std;

trie::trie()
{
    trieSize = 0;
    root = new node;
}

trie::~trie()
{
}

void trie::trieload(){

};

void trie::insertion(string input)
{
    // if the word is found to be in the trie, then fail insertion.
    if (searching(input) == true)
    {
        cout << "failure" << endl;
    }
    else if (searching(input) == false)
    {
        trieSize += 1;

        cout << "success" << endl;

        node *p_insertion = root; // set the initial traversing pointer to be at root.

        int j = 0;

        while (j < input.length())
        {
            int pos = input[j] - 'a';

            // if children of the node at the destinated index is not empty, traverse to the next node.
            if (p_insertion->children[pos] != NULL)
            {
                p_insertion = p_insertion->children[pos];
            }

            // if children of the node at the destinated index is empty, create a new node to insert character.
            else if (p_insertion->children[pos] == NULL)
            {
                p_insertion->children[pos] = new node;
                p_insertion = p_insertion->children[pos];
                p_insertion->character = input[j];
            }

            j++;
        }
        p_insertion->terminal = true;
        p_insertion = nullptr;
        delete p_insertion;
    }
};

bool trie::searching(string input)
{
    node *p_find = root; // set the initial traversing pointer to be at root.
    bool foundWord = false;

    int j = 0;

    while (j < input.size())
    {
        int pos = input[j] - 'a'; // get the index of the character

        // if children of the node at the destinated index is not empty, traverse to the next node.
        if (p_find->children[pos] != NULL)
        {
            p_find = p_find->children[pos];
        }
        // if children of the node at the destinated index is empty, no such word is found.
        else if (p_find->children[pos] == NULL)
        {
            return foundWord;
        }

        j++;
    }

    // if the last node is a termination of the word, the word exists in the trie.
    if (p_find->terminal == true)
    {
        foundWord = true;
    }

    p_find = nullptr;
    delete p_find;

    return foundWord;
};

void trie::erase(string input)
{
    if (searching(input) == false || trieSize == 0)
    {
        cout << "failure" << endl;
    }
    else if(searching(input) == true)
    {

    }
};

void trie::print()
{
    node *p_print = root;
    string targetWord;
};

void trie::spellcheck(string input){

};

bool trie::empty()
{
    if (trieSize == 0)
    {
        cout << "empty 1" << endl;
        return true;
    }
    else if (trieSize > 0)
    {
        cout << "empty 0" << endl;
    }

    return false;
};

void trie::clear()
{

    trieSize = 0;

    cout << "success" << endl;
};

void trie::countSize()
{

    cout << "number of words is " << trieSize << endl;
};