#ifndef DOUBLEHASHBUILD_H
#define DOUBLEHASHBUILD_H

#include "doublehashentry.hpp"
#include <vector>

using namespace std;

class hashBuild
{

private:
    int max_capacity; 
    int current_size;
    long long hashFunc1;
    long long hashFunc2;
    vector<doubleHashEntry> doubleHashtable;

public:
    hashBuild(); //constructor

    ~hashBuild(); //destructor

    void setSize(int n); //set the size of hashtable

    void insertKey(long long key, string lastname); //insert a student number into hashtable

    void searchEntry(long long key); //search for an entry in the hashtable

    void deleteEntry(long long key); //delete an entry from the hashtable

    long long hashValCalc(long long key, int n); //calculate the hashtable index with two hash functions 
};

#endif