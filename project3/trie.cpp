#include "trie.hpp"
#include <string>
#include <iostream>

using namespace std;

trie::trie()
{
    trieSize = 0;
    root = new node;
}

trie::~trie()
{
    clear_h(root);

    delete root;

    root = nullptr;
}

void trie::insertion(string input)
{
    // if the word is found to be in the trie, then fail insertion.
    if (searching(input) == false)
    {
        trieSize += 1;

        node *p_insertion = root; // set the initial traversing pointer to be at root.

        int j = 0;

        while (j < input.length())
        {
            int pos = input[j] - 'a';

            // if children of the node at the destinated index is not empty, traverse to the next node.
            if (p_insertion->children[pos] != NULL)
            {
                p_insertion = p_insertion->children[pos];
            }

            // if children of the node at the destinated index is empty, create a new node to insert character.
            else if (p_insertion->children[pos] == NULL)
            {
                p_insertion->children[pos] = new node;
                p_insertion = p_insertion->children[pos];
                p_insertion->character = input[j];
            }

            j++;
        }
        p_insertion->terminal = true;

        p_insertion = nullptr;

        delete p_insertion;
    }
};

bool trie::searching(string input)
{
    node *p_find = root; // set the initial traversing pointer to be at root.
    bool foundWord = false;

    int j = 0;

    while (j < input.size())
    {
        int pos = input[j] - 'a'; // get the index of the character

        // if children of the node at the destinated index is not empty, traverse to the next node.
        if (p_find->children[pos] != NULL)
        {
            p_find = p_find->children[pos];
        }
        // if children of the node at the destinated index is empty, no such word is found.
        else if (p_find->children[pos] == NULL)
        {
            return foundWord;
        }

        j++;
    }

    // if the last node is a termination of the word, the word exists in the trie.
    if (p_find->terminal == true)
    {
        foundWord = true;
    }

    p_find = nullptr;
    delete p_find;

    return foundWord;
};

void trie::erase(string input)
{
    if (searching(input) == false || trieSize == 0)
    {
        cout << "failure" << endl;
    }
    else if (searching(input) == true)
    {
        node *erase = root;
        erase_h(erase, input, 0);
        cout << "success" << endl;
        erase = nullptr;
        delete erase;
    }
};

void trie::erase_h(node *erase, string input, int pos)
{
    int index = input[pos] - 'a'; // get the index of the current character

    if ((erase->children[index])->terminal == false || pos != input.length() - 1)
    {
        if ((erase->children[index]) != NULL)
        {
            // cout << "current character " << erase->children[index]->character << endl;

            pos += 1;
            erase_h(erase->children[index], input, pos);

            if (((erase->children[index])->terminal == false) && (((erase->children[index])->numOfChildren((erase->children[index]))) == 0) && (erase->children[index] != root))
            {
                // cout << "delete character " << erase->children[index]->character << endl;
                delete erase->children[index];
                erase->children[index] = NULL;
            }
        }
    }
    else if ((erase->children[index])->terminal == true && pos == input.length() - 1)
    {
        if ((erase->children[index])->numOfChildren((erase->children[index])) == 0)
        {
            // cout << "delete " << erase->children[index]->character << endl;
            delete erase->children[index];
            erase->children[index] = NULL;
        }
        else if ((erase->children[index])->numOfChildren((erase->children[index])) != 0)
        {
            (erase->children[index])->terminal = false;
        }
        trieSize -= 1;
    }
};

void trie::print()
{
    node *print = root;
    string targetWord;
    print_h(print, targetWord);
    cout << endl;
    print = nullptr;
    delete print;
};

void trie::print_h(node *print, string targetWord)
{

    if (print->terminal == true)
    {
        targetWord.push_back(print->character[0]);
        cout << targetWord << " ";
    }
    else if (print->numOfChildren(print) > 0)
    {
        targetWord.push_back(print->character[0]);
    }

    int j = 0;
    while (j < 26)
    {
        if (print->children[j] != NULL)
        {
            print_h(print->children[j], targetWord);
        }

        j++;
    }

    targetWord.pop_back();
}

void trie::spellcheck(string input)
{

    if (searching(input) == true)
    {
        cout << "correct" << endl;
    }
    else
    {
        node *p_check = root;

        int check_index = input[0] - 'a';

        if (p_check->children[check_index] == NULL)
        {
            cout << endl;

            return;
        }

        spellcheck_h(p_check, input, 0);

        cout << endl;

        p_check = nullptr;

        delete p_check;
    }
};

void trie::spellcheck_h(node *p_spell, string input, int pos)
{
    int index = input[pos] - 'a'; // the index of the character

    // if the child of the character node is null, then we print the word starts with the traversed sub-string (ex. app)
    if (p_spell->children[index] == NULL || pos == input.length() || p_spell->numOfChildren(p_spell) == 0)
    {
        print_h(p_spell, input.substr(0, pos - 1));
    }
    // if the child of the character node is not null, then we recursively do the spellcheck.
    else if (p_spell->children[index] != NULL)
    {
        pos += 1;
        spellcheck_h(p_spell->children[index], input, pos);
    }

    p_spell = nullptr;

    delete p_spell;
}

void trie::clear()
{

    node *p_clear = root;

    clear_h(p_clear);

    trieSize = 0;

    p_clear = nullptr;

    delete p_clear;
};

void trie::clear_h(node *clear)
{

    if (clear->numOfChildren(clear) == 0)
    {
        return;
    }

    int j = 0;

    while (j < 26)
    {
        if (clear->children[j] != NULL)
        {
            clear_h(clear->children[j]);

            delete clear->children[j];

            clear->children[j] = NULL;
        }
        j++;
    }
}

bool trie::empty()
{
    if (trieSize == 0)
    {
        cout << "empty 1" << endl;
        return true;
    }
    else if (trieSize > 0)
    {
        cout << "empty 0" << endl;
    }

    return false;
};

void trie::countSize()
{

    cout << "number of words is " << trieSize << endl;
};