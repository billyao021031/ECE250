#include <iostream>
#include "node.hpp"
#include "trie.hpp"

using namespace std;

int main()
{
    string command = "";
    trie trie;

    while (command != "exit")
    {

        cin >> command;

        // if command is "load", load the corpus.txt into the trie.
        if (command == "load")
        {
            trie.trieload();
        }

        // if command is "i", insert a new word into the trie.
        else if (command == "i")
        {
            string iword;
            cin >> iword;
            trie.insertion(iword);
        }

        // if command is "s", search for a target word in the trie.
        else if (command == "s")
        {
            string sword;
            cin >> sword;
            if(trie.searching(sword) == true){
                cout << "found word" << endl;
            }else{
                cout << "not found" << endl;
            }
        }

        // if command is "e", erase a target word from the trie.
        else if (command == "e")
        {
            string eword;
            cin >> eword;
            trie.erase(eword);
        }

        // if command is "p", print all the word in the trie.
        else if (command == "p")
        {
            trie.print();
        }

        // if command is "spellcheck", check if the word is correctly spelled.
        else if (command == "spellcheck")
        {
            string checkword;
            cin >> checkword;
            trie.spellcheck(checkword);
        }

        // if command is "empty", check is the trie is empty.
        else if (command == "empty")
        {
            trie.empty();
        }

        // if command is "clear", clear the entire trie by deleting all the words.
        else if (command == "clear")
        {
            trie.clear();
        }

        // if command is "size", count the number of words in the trie.
        else if (command == "size")
        {
            trie.countSize();
        }
    }
}