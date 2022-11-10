#ifndef DOUBLEHASHENTRY_H
#define DOUBLEHASHENTRY_H

#include <string>

using namespace std;

class doubleHashEntry
{

private:
    long long SN; 
    string lastName;
    bool flag;

public:
    doubleHashEntry(); // constructor
    
    ~doubleHashEntry(); //destructor

    void setEntry(long long key, string name, bool f); //setter of an entry 

    long long getSN(); //getter of student number

    string getName(); //getter of student last name

    bool checkFlag(); //getter of the node flag
};

#endif