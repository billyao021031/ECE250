#ifndef CHAINHASHENTRY_H
#define CHAINHASHENTRY_H

#include <string>

using namespace std;

class chainHashEntry{

    private:
        long long SN;
        string lastName;
        chainHashEntry *p_next;

    public:
        chainHashEntry();
        ~chainHashEntry();

        friend class hashChain;
};


#endif 