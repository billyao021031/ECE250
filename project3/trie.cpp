#include "trie.hpp"
#include <string>
#include <iostream>

using namespace std;

// initialize member varibales
trie::trie()
{
    trieSize = 0;
    root = new node;
}

// destruct by clearing all the nodes in the trie
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

        // set the end character boolean value to be true (means the word stops here)
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
    // if the word is not found in the trie, or trie size is 0, erase fails
    if (searching(input) == false || trieSize == 0)
    {
        cout << "failure" << endl;
    }
    // if the word is found in the trie, start erasing
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

    // for the current node, if the next children node is not a terminal, or current node is not the second last one.
    if ((erase->children[index])->terminal == false || pos != input.length() - 1)
    {
        // if the next children node is not null;
        if ((erase->children[index]) != NULL)
        {
            // recursively keep traversing the word
            pos += 1;
            erase_h(erase->children[index], input, pos);

            if (((erase->children[index])->terminal == false) && (((erase->children[index])->numOfChildren((erase->children[index]))) == 0) && (erase->children[index] != root))
            {
                delete erase->children[index];
                erase->children[index] = NULL;
            }
        }
    }
    // for the current node, if the next children node is a terminal, or current node is the second last one.
    else if ((erase->children[index])->terminal == true && pos == input.length() - 1)
    {
        // if the next children node has no children, then we delete it
        if ((erase->children[index])->numOfChildren((erase->children[index])) == 0)
        {
            delete erase->children[index];
            erase->children[index] = NULL;
        }
        // if the next children node has children, then we remove the boolean terminal value
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
    // if the curremt node is terminal, push back the node character and cout the word.
    if (print->terminal == true)
    {
        targetWord.push_back(print->character[0]);
        cout << targetWord << " ";
    }
    // if current node's next children number is large than 0, push back the character
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

    node *p_check = root;

    int check_index = input[0] - 'a';

    // if the first node deos not exist in trie, then print new line.
    if (p_check->children[check_index] == NULL)
    {
        cout << endl;

        return;
    }

    spellcheck_h(p_check, input, 0);

    cout << endl;

    p_check = nullptr;

    delete p_check;
};

void trie::spellcheck_h(node *p_spell, string input, int pos)
{
    int index = input[pos] - 'a'; // the index of the character

    // if the position is equal the input length or it has no children at the index, then we print the word starts with the traversed sub-string (ex. app)
    if (pos == input.length() || p_spell->children[index] == NULL)
    {
        print_h(p_spell, input.substr(0, pos - 1));
    }
    else if (pos < input.length())
    {
        // if the child of the character node is not null, then we recursively do the spellcheck.
        if (p_spell->children[index] != NULL)
        {
            pos += 1;
            spellcheck_h(p_spell->children[index], input, pos);
        }
    }
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
    // if no children at the node, return the function
    if (clear->numOfChildren(clear) == 0)
    {
        return;
    }

    int j = 0;

    while (j < 26)
    {
        // if there is children at the next node, traverse and recursively do the clear
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

    cout << "number of words is: " << trieSize << endl;
};