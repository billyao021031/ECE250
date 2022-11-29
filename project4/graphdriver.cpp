#include <iostream>
#include <fstream>
#include "graph.hpp"

using namespace std;

int main()
{
    string command = "";

    while (command != "exit")
    {
        cin >> command;
        ifstream fin("paperCollabWeighted.txt");

        if (command == "load")
        {
        }
        else if (command == "i")
        {
        }
        else if (command == "p")
        {
        }
        else if (command == "d")
        {
        }
        else if (command == "mst")
        {
        }
        else if (command == "size")
        {
        }
        else{
            return 0;
        }
    }
}