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
        graph mygraph;

        int id_1;
        int id_2;
        double weight;

        ifstream fin("paperCollabWeighted.txt");

        if (command == "load")
        {
        }
        else if (command == "i")
        {
            cin >> id_1 >> id_2 >> weight;
            mygraph.insertion(id_1, id_2, weight);
        }
        else if (command == "p")
        {
            cin >> id_1;
            mygraph.print(id_1);
        }
        else if (command == "d")
        {
            cin >> id_1;
            mygraph.deletion(id_1);
        }
        else if (command == "mst")
        {
        }
        else if (command == "size")
        {
        }
        else
        {
            return 0;
        }
    }
}