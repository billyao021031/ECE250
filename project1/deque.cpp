#include <iostream>
#include "deque.hpp"
#include "node.hpp"
#include <string>

using namespace std;

    deque::deque()
    {
        numOfNode = 0;
        p_head = NULL;
        p_tail = NULL;
    }
    
    deque::~deque()
    {
        while (empty() == false) 
        {
            node *p_clear = p_head; 
            numOfNode = numOfNode - 1; 
            p_head = p_head->p_next; 
            delete p_clear; 
        }
        p_tail = NULL;
    };

    void deque::setQueue(int size)
    {
        //assign the input size to the variable "capacity"
        capacity = size;

        cout << "success" << endl;

        return;
    };

    void deque::push_front(string n, string l)
    {
        //if the list is not full but contains several nodes
        if (numOfNode > 0 && numOfNode < capacity)
        {
            node *p_temp = new node;
            p_temp->link_name = n;
            p_temp->link_address = l;
            p_head->p_previous = p_temp;
            p_temp->p_next = p_head;
            p_head = p_temp;
            p_temp = NULL;
            numOfNode += 1;

            cout << "success" << endl;
        }
        //if the list is already full
        else if (isFull())
        {
            //delete the tail node
            node *p_delete = p_tail;
            p_tail = p_delete->p_previous;
            p_tail->p_next = NULL;

            node *p_add = new node;
            p_add->link_name = n;
            p_add->link_address = l;
            p_head->p_previous = p_add;
            p_add->p_next = p_head;
            p_head = p_add;
            p_add = NULL;

            cout << "success" << endl;
        }
        //if the list is empty
        else if (empty() == true)
        {
            p_head = new node;
            p_head->link_name = n;
            p_head->link_address = l;
            p_tail = p_head;
            numOfNode += 1;

            cout << "success" << endl;
        }
    };

    void deque::push_back(string n, string l)
    {

        if (numOfNode > 0 && numOfNode < capacity)
        {
            node *p_temp = new node;
            p_temp->link_name = n;
            p_temp->link_address = l;
            p_temp->p_previous = p_tail;
            p_tail->p_next = p_temp;
            p_tail = p_temp;
            p_temp = NULL;
            numOfNode += 1;

            cout << "success" << endl;
        }
        else if (isFull())
        {
            node *p_delete = p_head;
            p_head = p_delete->p_next; // point p_head to the next node
            p_head->p_previous = NULL; // delete the previous node from the current p_head

            node *p_add = new node;
            p_add->link_name = n;
            p_add->link_address = l;
            p_add->p_previous = p_tail;
            p_tail->p_next = p_add;
            p_tail = p_add;
            p_add = NULL;

            cout << "success" << endl;
        }
        else if (empty() == true)
        {
            p_tail = new node;
            p_tail->link_name = n;
            p_tail->link_address = l;
            p_head = p_tail;
            numOfNode += 1;

            cout << "success" << endl;
        }
    };

    void deque::pop_front()
    {
        if (numOfNode == 1)
        {
            p_head = nullptr;
            p_tail = nullptr;
            delete p_head;
            numOfNode--;
            cout << "success" << endl;
        }
        else if (numOfNode > 1)
        {
            node *p_pop = p_head;
            p_head = p_pop->p_next;
            p_head->p_previous = NULL;
            numOfNode -= 1;

            cout << "success" << endl;
        }
        else if (empty() == true)
        {
            cout << "failure" << endl;
        }
    };

    void deque::pop_back()
    {
        if (numOfNode == 1)
        {

            p_head = nullptr;
            p_tail = nullptr;
            delete p_tail;
            numOfNode--;

            cout << "success" << endl;
        }
        else if (numOfNode > 1)
        {

            node *p_pop = p_tail;
            p_tail = p_pop->p_previous;
            p_tail->p_next = NULL;
            numOfNode -= 1;

            cout << "success" << endl;
        }
        else if (empty() == true)
        {

            cout << "failure" << endl;
        }
    };

    void deque::clear()
    {
        while (empty() == false)
        {
            numOfNode--;
            node *p_clear = p_head;
            p_head = p_head->p_next;
            delete p_clear;
        }
        p_tail = NULL;
    };

    void deque::size()
    {
        cout << "size is " << numOfNode << endl;
    };

    void deque::front()
    {
        if (empty() == false)
        {
            cout << "front is " << p_head->link_name << " " << p_head->link_address << endl;
        }
        else
        {
            cout << "failure" << endl;
        }
    };

    void deque::back()
    {
        if (empty() == false)
        {
            cout << "back is " << p_tail->link_name << " " << p_tail->link_address << endl;
        }
        else
        {
            cout << "failure" << endl;
        }
    };

    bool deque::empty()
    {
        return (numOfNode == 0);
    };

    void deque::findName(string n)
    {
        string targetName = n;
        bool foundName = false;
        node *p_find = new node;
        p_find = p_head;
        while (p_find != NULL)
        {
            if (p_find->link_name == targetName)
            {
                cout << "found " << p_find->link_name << " " << p_find->link_address << endl;
                foundName = true;
                break;
            }
            p_find = p_find->p_next;
        }

        if (foundName == false)
        {
            cout << "not found " << targetName << endl;
        }
    };

    void deque::print()
    {
        if (empty() == false)
        {
            node *p_traverse = new node; // create a new node to traverse the list
            p_traverse = p_tail; //starts from the tail of the list
            while (p_traverse != NULL)
            {
                cout << p_traverse->link_name << " " << p_traverse->link_address << endl;
                p_traverse = p_traverse->p_previous;
            }
        }
        else
        {
            cout << "deque is empty" << endl;
        }
    };

    bool deque::isFull()
    {
        if (numOfNode < capacity) // if the number of nodes is few than the capacity
        {
            return false; // false -- it is not full
        }

        return true; // true -- it is full
    };
