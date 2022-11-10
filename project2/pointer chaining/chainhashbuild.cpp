#include <iostream>
#include <cmath>
#include <vector>
#include "chainhashbuild.hpp"

hashChain::hashChain()
{
    max_capacity = 0;
    chainHashtable.resize(0);
}

hashChain::~hashChain()
{
    int i = 0;
    while (i < max_capacity)
    {
        chainHashEntry *p_temp = chainHashtable[i];
        while (p_temp != NULL)
        {
            chainHashEntry *p_destruct = p_temp;
            p_temp = p_temp->p_next;
            delete p_destruct;
        }
    }
}

void hashChain::setSize(int n)
{
    max_capacity = n;
    chainHashtable.resize(max_capacity);
    cout << "success" << endl;
}

void hashChain::insertKey(long long key, string lastname)
{
    long long hashVal = key % max_capacity;
    chainHashEntry *p_insert = chainHashtable[hashVal];
    bool insertion;

    if (p_insert == NULL)
    {
        chainHashtable[hashVal] = new chainHashEntry;
        chainHashtable[hashVal]->SN = key;
        chainHashtable[hashVal]->lastName = lastname;
        insertion = true;
    }

    else if (p_insert->p_next == NULL)
    {
        if (p_insert->SN == key)
        {
            insertion = false;
        }
        else if (p_insert->SN > key)
        {
            chainHashtable[hashVal]->p_next = new chainHashEntry;
            (chainHashtable[hashVal]->p_next)->SN = key;
            (chainHashtable[hashVal]->p_next)->lastName = lastname;
            insertion = true;
        }
        else if (p_insert->SN < key)
        {
            chainHashtable[hashVal] = new chainHashEntry;
            chainHashtable[hashVal]->p_next = p_insert;
            chainHashtable[hashVal]->SN = key;
            chainHashtable[hashVal]->lastName = lastname;
            insertion = true;
        }
    }
    else
    {
        chainHashEntry *p_current = p_insert;
        chainHashEntry *p_following = p_insert->p_next;

        if (key > (p_current->SN) && key > (p_following->SN))
        {
            chainHashtable[hashVal] = new chainHashEntry;
            chainHashtable[hashVal]->p_next = p_insert;
            chainHashtable[hashVal]->SN = key;
            chainHashtable[hashVal]->lastName = lastname;
            insertion = true;
        }
        else
        {
            while (p_following != NULL)
            {
                if (key < (p_current->SN) && key > (p_following->SN))
                {
                    p_current->p_next = new chainHashEntry;
                    (p_current->p_next)->SN = key;
                    (p_current->p_next)->lastName = lastname;
                    (p_current->p_next)->p_next = p_following;
                    insertion = true;
                    break;
                }
                else if (p_current->SN == key || p_following->SN == key)
                {
                    insertion = false;
                    break;
                }
                
                p_current = p_following;
                p_following = p_following->p_next;
            }

            if (p_following == NULL)
            {
                p_current->p_next = new chainHashEntry;
                (p_current->p_next)->SN = key;
                (p_current->p_next)->lastName = lastname;
                insertion = true;
            }
        }
    }

    if (insertion == true)
    {
        cout << "success" << endl;
    }
    else
    {
        cout << "failure" << endl;
    }
}

void hashChain::searchEntry(long long key)
{
    bool foundKey = false;
    long long hashVal = key % max_capacity;
    chainHashEntry *p_search = chainHashtable[hashVal];

    if (p_search != NULL)
    {
        while (p_search != NULL)
        {
            if (p_search->SN == key)
            {
                cout << "found " << p_search->lastName << " in " << hashVal << endl;
                foundKey = true;
                break;
            }
            else
            {
                p_search = p_search->p_next;
            }
        }
    }

    if (foundKey == false)
    {
        cout << "not found" << endl;
    }
}

void hashChain::deleteEntry(long long key)
{
    long long hashVal = key % max_capacity;
    chainHashEntry *p_delete = chainHashtable[hashVal];
    bool deletion;

    if (p_delete == NULL)
    {
        deletion = false;
    }
    else if ((p_delete->p_next) == NULL)
    {
        if ((p_delete->SN) == key)
        {
            p_delete = nullptr;
            delete p_delete;
            chainHashtable[hashVal] = NULL;
            deletion = true;
        }
        else
        {
            deletion = false;
        }
    }
    else
    {
        chainHashEntry *p_previous = p_delete;
        chainHashEntry *p_following = p_delete->p_next;

        if (p_previous->SN == key)
        {
            chainHashtable[hashVal] = p_following;
            p_delete = nullptr;
            p_previous = nullptr;
            delete p_delete;
            delete p_previous;
            deletion = true;
        }
        else
        {
            while (p_following != NULL)
            {
                if (p_following->SN == key)
                {
                    chainHashEntry *p_temp = p_following;
                    p_following = p_temp->p_next;
                    p_previous->p_next = p_following;
                    p_temp = nullptr;
                    delete p_temp;
                    deletion = true;
                    break;
                }
                else
                {
                    p_previous = p_following;
                    p_following = p_following->p_next;
                }
            }
            if (p_following == NULL && deletion == false)
            {
                cout << "failure" << endl;
            }
        }
    }
    if (deletion == false)
    {
        cout << "failure" << endl;
    }
    else
    {
        cout << "success" << endl;
    }
}

void hashChain::print(int n)
{
    chainHashEntry *p_temp = chainHashtable[n];

    if (p_temp == NULL)
    {
        cout << "chain is empty" << endl;
    }
    else if (p_temp != NULL && (p_temp->p_next) == NULL)
    {
        cout << p_temp->SN << endl;
    }
    else
    {
        while ((p_temp->p_next) != NULL)
        {
            cout << p_temp->SN << " ";

            p_temp = p_temp->p_next;

            if ((p_temp->p_next) == NULL)
            {
                cout << p_temp->SN << endl;
                break;
            }
        }
    }
}
