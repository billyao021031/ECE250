#ifndef DEQUE_H
#define DEQUE_H
#include <string>
#include "node.hpp"

using namespace std;

class deque
{
private:
    int numOfNode; //number of the current nodes in the list
    int capacity; //size of the linkedlist
    node *p_head; //head node
    node *p_tail; //tail node

public:
    deque();
    //constructor
    
    ~deque();
    //destructor

    void setQueue(int size);
    //set up the size of the deque and compare with number of nodes  

    void push_front(string n, string l);
    /* change on p_head
    push the URL to the p_head position, and switch p_head to the front
    */

    void push_back(string n, string l);
    /* change on p_tail
    push the URL to the p_tail position, and switch p_tail to the back
    */

    void pop_front();
    /* change on p_head
    pop out the first URL from the list, and change p_head to the second one
    */

    void pop_back();
    /* change on p_tail
    pop out the last URL from the list, and change p_tail to the second last one
    */

    void clear();
    /*  similar as destructor
    use a pointer p_clear to travese through the list and delete each node
    */

    void size();
    //cout the integer "numOfNode"

    void front();
    //cout the head of the list

    void back();
    //cout the tail of the list

    bool empty();
    /*return the boolean value of (numOfNode > 0)
    reusable in the above functions
    */

    void findName(string n);
    /*the function takes in the parameter 
    and then use p_temp to traverse through each node to access and compare the URL name
    */

    void print();
    /* use p_temp to traverse through each node
    print out the URL name and address held on each node
    */

    bool isFull();
    //Compare and contrast value "numOfNode" and "capacity" to return boolean value 
};

#endif