#include "trie.hpp"
#include <string>
#include <iostream>

using namespace std;

trie::trie()
{
    root = NULL;
}

trie::~trie()
{
}

void trie::trieload(){

};

void trie::insertion(string word){

    node *p_insertion = root;


};

void trie::searching(string word){

};

void trie::erase(string word){

};

void trie::print(){

};

void trie::spellcheck(string word){

};

bool trie::empty(){
    if(trieSize == 0){
        cout << "empty 1" << endl;
        return true;
    }else if(trieSize > 0){
        cout << "empty 0" << endl;
        return false;
    }
};

void trie::clear(){


};

void trie::countSize(){

    cout << "number of words is " << trieSize << endl;

};