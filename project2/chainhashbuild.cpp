#include "chainhashbuild.hpp"
#include "chainhashentry.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructor
hashtable::hashtable()
{
    max_capacity = 0;
    htable.resize(0);
}


//destrcutor
hashtable::~hashtable()
{   
    htable.clear();
}


void hashtable::setSize(int n)
{
    max_capacity = n;
    htable.resize(max_capacity);
    cout << "success" << endl;
}


void hashtable::insertKey(long long key, string lastname)
{

    // Get the index of hashtable
    long long h = key % max_capacity;
    bool insertion = true;
    
    int i = 0;

    //loop through the entire chain
    while(i < sizeOfChain(h)){

        //if the input is already in the chain, insertion fails
        if(htable[h].hashchain[i].getKey() == key){
            insertion = false;
            cout << "failure" << endl;
            break;
        }
        i++;
    }

    //if the insertion is successful
    if(insertion == true){

        node insert_node;
        insert_node.setNode(key, lastname);
        htable[h].hashchain.push_back(insert_node); //use push_back function to push the entry node into the chain

        cout << "success" << endl;

        //if the the previous node is smaller than the next node in the chain, swap the position
        int j = sizeOfChain(h) -1;

        while(j > 0){
            if(htable[h].hashchain[j-1].getKey() < htable[h].hashchain[j].getKey()){
                node swapping = htable[h].hashchain[j-1];
                htable[h].hashchain[j-1] = htable[h].hashchain[j];
                htable[h].hashchain[j] = swapping;
            }
            j--;
        }

    }
}


void hashtable::deleteEntry(long long key)
{
    // get the index of hashtable
    long long h = key % max_capacity;
    bool deletion = false;
    int i = 0;

    //if the selected chain is not empty
    if (sizeOfChain(h) > 0){

        //loop through the chain to check the equal student key
        while (i < sizeOfChain(h))
        {   
            if (htable[h].hashchain.at(i).getKey() == key)
            {
                htable[h].hashchain.erase(htable[h].hashchain.begin() + i);
                deletion = true;
            }
            i++;
        }
    }

    if (deletion == true)
    {
        cout << "success" << endl;
    }
    else if (deletion == false)
    {
        cout << "failure" << endl;
    }
}


void hashtable::searchEntry(long long key)
{

    // get the index of hashtable
    long long h = key % max_capacity;

    bool found;

    // loop through the chain to find the element.
    int i = 0;
    while (i < sizeOfChain(h))
    {

        if (htable[h].hashchain.at(i).getKey() == key)
        {
            cout << "found " << htable[h].hashchain.at(i).getName() << " in " << h << endl;
            found = true;
            break;
        }
        else
        {
            found = false;
        }
        i++;
    }

    if (found == false)
    {
        cout << "not found" << endl;
    }
}


void hashtable::print(long long key)
{

    // get the index of hashtable
    long long h = key % max_capacity;

    // loop through the chain to print all elements
    int i = 0;

    //if the chain is empty, print empty message
    if (sizeOfChain(h) == 0)
    {
        cout << "chain is empty" << endl;
    }
    else
    {
        while (i < sizeOfChain(h))
        {
            cout << htable[h].hashchain.at(i).getKey();

            if (i < sizeOfChain(h) - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }

            i++;
        }
    }
}

//return the size of the selected chain
int hashtable::sizeOfChain(long long h){

    int chainSize = htable[h].hashchain.size();

    return chainSize;
}