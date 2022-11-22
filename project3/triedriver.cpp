#include <iostream>
#include <fstream>
#include "node.hpp"
#include "trie.hpp"

using namespace std;

int main()
{
    string command = "";
    trie myTrie;

    while (command != "exit")
    {
        cin >> command;
        ifstream fin("corpus.txt");

        string addWord;
        // if command is "load", load the corpus.txt into the trie.
        if (command == "load")
        {
            while (fin >> addWord)
            {
                myTrie.insertion(addWord);
            }
            cout << "success" << endl;
        }

        // if command is "i", insert a new word into the trie.
        else if (command == "i")
        {
            string iword;
            cin >> iword;

            try
            {
                int k = 0;

                while (k < iword.length())
                {
                    int var = iword[k];
                    if ((var < 97) || (var > 122))
                    {
                        throw illegal_exception();
                    }
                    k++;
                }

                if (myTrie.searching(iword) == true)
                {
                    cout << "failure" << endl;
                }
                else
                {
                    myTrie.insertion(iword);
                    cout << "success" << endl;
                }
            }
            catch (const std::exception &ill)
            {
                cout << "illegal argument" << endl;
            }
        }

        // if command is "s", search for a target word in the trie.
        else if (command == "s")
        {
            string sword;
            cin >> sword;
            try
            {
                int k = 0;

                while (k < sword.length())
                {
                    int var = sword[k];
                    if ((var < 97) || (var > 122))
                    {
                        throw illegal_exception();
                    }
                    k++;
                }

                if (myTrie.searching(sword) == true)
                {
                    cout << "found " << sword << endl;
                }
                else
                {
                    cout << "not found" << endl;
                }
            }
            catch (const std::exception &ill)
            {
                cout << "illegal argument" << endl;
            }
        }

        // if command is "e", erase a target word from the trie.
        else if (command == "e")
        {
            string eword;
            cin >> eword;
            try
            {
                int k = 0;

                while (k < eword.length())
                {
                    int var = eword[k];
                    if ((var < 97) || (var > 122))
                    {
                        throw illegal_exception();
                    }
                    k++;
                }
                myTrie.erase(eword);
            }
            catch (const std::exception &ill)
            {
                cout << "illegal argument" << endl;
            }
        }

        // if command is "p", print all the word in the trie.
        else if (command == "p")
        {
            myTrie.print();
        }

        // if command is "spellcheck", check if the word is correctly spelled.
        else if (command == "spellcheck")
        {
            string checkword;
            cin >> checkword;
            if (myTrie.searching(checkword) == true)
            {
                cout << "correct" << endl;
            }
            else
            {
                myTrie.spellcheck(checkword);
            }
        }

        // if command is "empty", check is the trie is empty.
        else if (command == "empty")
        {
            myTrie.empty();
        }

        // if command is "clear", clear the entire trie by deleting all the words.
        else if (command == "clear")
        {
            myTrie.clear();
            cout << "success" << endl;
        }

        // if command is "size", count the number of words in the trie.
        else if (command == "size")
        {
            myTrie.countSize();
        }
    }
}