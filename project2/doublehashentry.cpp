#include "doublehashentry.hpp"
#include <string>

using namespace std;

//constructor 
doubleHashEntry::doubleHashEntry()
{
    SN = 0;
    lastName = "";
    flag = 0;
}

//destructor
doubleHashEntry::~doubleHashEntry()
{
}

//setter of the entry node
void doubleHashEntry::setEntry(long long key, string name, bool f)
{
    SN = key;
    lastName = name;
    flag = f;
}

//getter of the student number
long long doubleHashEntry::getSN()
{
    return SN;
}

//getter of the student last name
string doubleHashEntry::getName()
{
    return lastName;
}

//getter of the flag
bool doubleHashEntry::checkFlag()
{
    return flag;
}
