#include <iostream>
#include <string>
#include "trie.h"

node::node()
{
    letter = "";
    isWordEnd = false;
    is_push = false;
    for (int i = 0; i < size; i++)
    {
        child[i] = NULL;
    }
}

node::~node()
{
    for(int i = 0; i < size ; i++)
    {
        this ->child[i]= NULL;
        delete[] this->child[i];
    }
}

trie::trie()
{
    count = 0;
    root = new node;
}

trie::~trie()
{

}

bool trie::is_find(std::string word)
{
    node *p = root;
    for (int i = 0; i < word.length(); ++i)
    {
        int index = word[i] - 'a';
        if (p->child[index] == NULL)
        {
            return false;
        }
        else if (p->child[index] != NULL)
        {
            p = p->child[index];
        }
    }

    if (p->isWordEnd == true)
    {
        return true;
    }
    else
    {
        return false;
    }

    p = nullptr;
    delete[] p;
}

void trie::addword(std::string word)
{

    node *p = root;

    for (int i = 0; i < word.length(); ++i)
    {
        int index = word[i] - 'a';
        if (p->child[index] == NULL)
        {
            p->child[index] = new node;
            node *temp = p;
            p = p->child[index];
            p->letter = word[i];
            p->parent = temp;
            temp = nullptr;
            delete[] temp;
            std::cout << p->letter << "  " << index << std::endl;
        }
        else
        {
            p = p->child[index];
            std::cout << p->letter << "  " << index << std::endl;
        }
    }
    p->isWordEnd = true;
    count++;
    std::cout << count << " " << std::endl;
    p = nullptr;
    delete[] p;
}

int trie::is_empty(node *p)
{
    int a = 0;
    for (int i = 0; i < size; ++i)
    {
        if (p->child[i] != NULL)
        {
            a++;
        }
    }

    return a;
}

void trie::empty()
{
    node *p = root;
    if (is_empty(p) > 0)
    {
        std::cout << "empty 1" << std::endl;
    }
    else if (is_empty(p) == 0)
    {
        std::cout << "empty 0" << std::endl;
    }

    p = nullptr;
    delete[] p;
}

void trie::print()
{
    node *p = root;
    std::string word = "";
    r_print(p, word);
    p = nullptr;
    delete[] p;
    std::cout<<std::endl;
}

void trie::r_print(node *p, std::string word)
{

    if((p->isWordEnd == true))
    {   
        // std::cout << word << "  *  " << std::endl;
        word.push_back(p->letter[0]);
        p->is_push = true;
        std::cout << word << " ";

    }else if(is_empty(p) > 1)
    {
        word.push_back(p->letter[0]);
        p->is_push = true;

    }

    for(int i = 0; i < size ; i++)
    { 
        if((p->child[i] != NULL) && (p->is_push == false))
        {   
            word.push_back(p->letter[0]);
            // std::cout << "level of " << p->letter << "  word  " << word << std::endl;
            // std::cout <<"children " << (p->child[i])->letter << std::endl;
            r_print(p->child[i], word);
        }
        else if((p->child[i] != NULL) && (p->is_push == true)){
            // std::cout << "level of " << p->letter << "  word1  " << word << std::endl;
            // std::cout <<"children " << (p->child[i])->letter << std::endl;
            r_print(p->child[i], word);
        }

    }

    word.pop_back();
    // std::cout << word << " pop " << p->letter << std::endl;
}

void trie::erase(std::string word)
{
    node *p = root;
    r_erase(p, word, 0);
    p = nullptr;
    delete[] p;
} 

void trie::r_erase(node *p, std::string word, int iw)
{   
    if( (iw == word.length()) && (p->isWordEnd == true))
    {
        if(is_empty(p) == 0)
        {   
            p = p->parent;
            int index = word[iw - 1] - 'a';
            std::cout << "delete1  " << p->letter << " index1  " << index << std::endl;
            p->child[index] = NULL;
            delete[] p->child[index];
            // p->child[index] = nullptr;
        } 
        else{
            int index = word[iw - 1] - 'a';
            p = p->parent;
            std::cout << "erase terminal " << p->letter << std::endl;
            (p->child[index])->isWordEnd = false;
            (p->child[index])->is_push = false;
        }
        count --;
        // return;
    }
    else{
         int index = word[iw] - 'a';

        if(p->child[index] != nullptr)
        {
            std::cout << "current letter  " << p->letter << " empty " << is_empty(p) << std::endl;
            r_erase(p->child[index], word, iw + 1);

            if((p->isWordEnd == false) && (is_empty(p) == 0) && (p != root))
            {   
                p = p->parent;
                p->child[index] = NULL;
                delete[] p->child[index];
                std::cout << "delete2  " << p->letter << "index2  " << index << std::endl;

            }
        }
        return;
    }
}
