#ifndef CHAINHASHENTRY_H
#define CHAINHASHENTRY_H

#include <vector>
#include <string>

using namespace std;

class node{

    private:
        long long SN;
        string lastname;

    friend class hashtable;

    public:
        node(); // constructor

        ~node();  //destructor

        void setNode(long long key, string name); //setter of the node

        long long getKey(); //getter of the student number
        
        string getName();  //getter of the student last name
};

class chain
{
private:
    vector<node> hashchain;

    friend class hashtable;

};

#endif