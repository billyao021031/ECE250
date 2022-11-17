#include "node.hpp"
#include <string>

node::node(){
    terminal = false;
    character = "";
    parent = NULL;
    for(int i = 0; i < 26; i++){
        children[i] = NULL;
    }
}

node::~node(){

}