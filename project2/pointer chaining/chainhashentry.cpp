#include "chainhashentry.hpp"
#include <string>

using namespace std;

chainHashEntry::chainHashEntry(){
    SN = 0;
    lastName = "";
    p_next =NULL;
}

chainHashEntry::~chainHashEntry(){
    p_next = nullptr;
    delete p_next;
}

