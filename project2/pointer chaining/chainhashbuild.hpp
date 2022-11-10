#ifndef CHAINHASHBUILD_H
#define CHAINHASHBUILD_H

#include "chainhashentry.hpp"
#include <vector>

class hashChain
{

private:
    int max_capacity;
    vector <chainHashEntry*> chainHashtable;

public:
    hashChain();
    ~hashChain();

    void setSize(int n);

    void insertKey(long long key, string lastname);

    void searchEntry(long long key);

    void deleteEntry(long long key);

    void print(int n);
};

#endif