#ifndef CHAINHASHBUILD_H
#define CHAINHASHBUILD_H

#include "chainhashentry.hpp"
#include <vector>
#include <string>

using namespace std;

class hashtable
{
private:
    int max_capacity;
    vector<chain> htable;

public:

    hashtable(); //constructor

    ~hashtable(); //destructor

    void setSize(int n);  //set the size of hashtable

    void insertKey(long long key, string lastname); //insert a student number into hashtable

    void searchEntry(long long key); //search for an entry in the hashtable

    void deleteEntry(long long key); //delete an entry from the hashtable

    void print(long long key); //print all elements in a selected chain

    int sizeOfChain(long long key); //return the size of a selected chain
};

#endif