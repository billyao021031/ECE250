#include "doublehashbuild.hpp"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//constructor
hashBuild::hashBuild()
{
    max_capacity = 0;
    current_size = 0;
    doubleHashtable.resize(0);
}


//destructor
hashBuild::~hashBuild()
{
    doubleHashtable.clear();
}


void hashBuild::setSize(int n)
{
    //set maximum capacity to be input size and assign it to the hashtable vector
    max_capacity = n;
    doubleHashtable.resize(n);
    cout << "success" << endl;
}


void hashBuild::insertKey(long long key, string lastname)
{
    //if the hashtable is full, then insertion fails.
    if (current_size == max_capacity)
    {
        cout << "failure" << endl;
    }
    //if the hashtable is not full yet.
    else
    {
        int p = 0;

        //loop through the entire hashtable
        while (p <= max_capacity)
        {
            long long hashVal = hashValCalc(key, p);

            //if the student number at position [hashVal] is equal to input key, insertion fails
            if (doubleHashtable[hashVal].getSN() == key)
            {
                cout << "failure" << endl;
                break;
            }
            //if no student number and student name stored at position [hashVal], insertion success
            else if (doubleHashtable[hashVal].getSN() == 0 && doubleHashtable[hashVal].getName() == "")
            {
                doubleHashtable[hashVal].setEntry(key, lastname, 1);
                current_size++;
                cout << "success" << endl;
                break;
            }
            //if the student number and student lastname stored at position [hashVal] does not equal the input, increase the iterator
            else if (doubleHashtable[hashVal].getSN() != 0 && doubleHashtable[hashVal].getName() != "")
            {
                p++;
            }
        }
    }
}


void hashBuild::searchEntry(long long key)
{
    int p = 0;
    bool foundKey = false; // check if the entry is found in the table

    //loop through the entire hashtable
    while (p < max_capacity)
    {
        long long hashVal = hashValCalc(key, p);

        //if the student number at position [hashVal] is equal to input key, searching success
        if (doubleHashtable[hashVal].getSN() == key)
        {
            cout << "found " << doubleHashtable[hashVal].getName() << " in " << hashVal << endl;
            foundKey = true;
            break;
        }
        //if the passed-by node has never been used, searching fails (means that the hash function never proceeded to this point)
        else if (doubleHashtable[hashVal].checkFlag() == 0)
        {
            foundKey = false;
            break;
        }
        //if the student number at last [hashVal] is not equal to the key, searching fails
        else if ((p == max_capacity - 1) && (doubleHashtable[hashVal].getSN() != key))
        {
            foundKey = false;
            break;
        }
        //if the passed-by node has been used but the key still not equal to student number, increase iterator
        else if (doubleHashtable[hashVal].checkFlag() == 1 && doubleHashtable[hashVal].getSN() != key)
        {
            p++;
        }
    }

    if (foundKey == false)
    {
        cout << "not found" << endl;
    }
}


void hashBuild::deleteEntry(long long key)
{
    int p = 0;
    bool deletion = false; // check if the deletion success in the table

     //loop through the entire hashtable
    while (p < max_capacity)
    {
        long long hashVal = hashValCalc(key, p);

        ////if the student number at position [hashVal] is equal to input key, deletion success
        if (doubleHashtable[hashVal].getSN() == key)
        {
            doubleHashtable[hashVal].setEntry(0, "", 1);
            current_size--;
            deletion = true;
            cout << "success" << endl;
            break;
        }

        //if the passed-by node has never been used, deletion fails 
        else if (doubleHashtable[hashVal].checkFlag() == 0)
        {
            deletion = false;
            break;
        }

        //if the student number at last [hashVal] is not equal to the key, deletion fails
        else if ((p == max_capacity - 1) && (doubleHashtable[hashVal].getSN() != key))
        {
            deletion = false;
            break;
        }

         //if the passed-by node has been used but the key still not equal to student number, increase iterator
        else if (doubleHashtable[hashVal].checkFlag() == 1 && doubleHashtable[hashVal].getSN() != key)
        {
            p++;
        }
    }

    if (deletion == false)
    {
        cout << "failure" << endl;
    }
}


long long hashBuild::hashValCalc(long long key, int n)
{
    //hash function 1
    hashFunc1 = key % max_capacity; 

    //hash function 2
    hashFunc2 = (long long)(floor(key / max_capacity)) % max_capacity;

    if (hashFunc2 % 2 == 0)
    {
        hashFunc2++;
    }

    return (hashFunc1 + (n * hashFunc2)) % max_capacity;
}
