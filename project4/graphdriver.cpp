#include <iostream>
#include <fstream>
#include "graph.hpp"

using namespace std;

int main()
{
    string command = "";
    graph mygraph;

    while (command != "exit")
    {
        cin >> command;
        ifstream fin("paperCollabWeighted.txt");

        int id_1;
        int id_2;
        double weight;
        string addId;

        if (command == "load")
        {
            while (fin >> id_1 >> id_2 >> weight)
            {
                mygraph.insertion(id_1, id_2, weight);
            }
            cout << "success" << endl;
        }
        else if (command == "i")
        {
            cin >> id_1 >> id_2 >> weight;
            bool is_find = mygraph.findCombo(id_1, id_2);
            if(is_find == false){
                mygraph.insertion(id_1, id_2, weight);
                cout << "success" << endl;
            }else{
                cout << "failure" << endl;
            }
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
            cin >> id_1;
            mygraph.getMST(id_1);
        }
        else if (command == "size")
        {
            mygraph.getSize();
        }
        else
        {
            return 0;
        }
    }
}