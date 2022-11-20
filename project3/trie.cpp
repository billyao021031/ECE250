#include "trie.hpp"
#include <string>
#include <iostream>

using namespace std;

trie::trie()
{
    trieSize = 0;
    root = NULL;
}

trie::~trie()
{
}

void trie::trieload(){

};

void trie::insertion(string word)
{

    node *p_insertion = root;

    int i = 0;

    while(i < word.length()){
        int pos = word[i] - 'a';

        
        i++;
    }
};

void trie::searching(string word){
    



};

void trie::erase(string word){

};

void trie::print(){

};

void trie::spellcheck(string word){

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

void trie::clear(){

};

void trie::countSize()
{

    cout << "number of words is " << trieSize << endl;
};