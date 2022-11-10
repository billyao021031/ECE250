#include "chainhashentry.hpp"
#include <string>

using namespace std;

// constructor
node::node(){
    SN = 0;
    lastname = "";
}

//destructor
node::~node(){

}

//setter of the node
void node::setNode(long long key, string name){
    SN = key;
    lastname = name;
}

//getter of the student number
long long node::getKey(){
    return SN;
}

//getter of the student last name
string node::getName(){
    return lastname;
}