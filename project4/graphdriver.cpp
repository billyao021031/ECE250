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

        //load the data set
        if (command == "load")
        {
            while (fin >> id_1 >> id_2 >> weight)
            {
                mygraph.insertion(id_1, id_2, weight);
            }
            cout << "success" << endl;
        }

        //insertion
        else if (command == "i")
        {
            cin >> id_1 >> id_2 >> weight;

            try
            {
                if (id_1 > 23133 || id_1 < 1 || id_2 > 23133 || id_2 < 1 || weight < 0.0 || weight > 1.0)
                {
                    throw illegal_exception();
                }
                else
                {
                    bool is_find = mygraph.findCombo(id_1, id_2);
                    if (is_find == false)
                    {
                        mygraph.insertion(id_1, id_2, weight);
                        cout << "success" << endl;
                    }
                    else
                    {
                        cout << "failure" << endl;
                    }
                }
            }
            catch (illegal_exception alert)
            {
                cout << alert.msg() << endl;
            }
        }

        //printing
        else if (command == "p")
        {
            cin >> id_1;

            try
            {
                if (id_1 > 23133 || id_1 < 1)
                {
                    throw illegal_exception();
                }
                else
                {
                    mygraph.print(id_1);
                }
            }
            catch (illegal_exception alert)
            {
                cout << alert.msg() << endl;
            }
        }

        //deletion
        else if (command == "d")
        {
            cin >> id_1;

            try
            {
                if (id_1 > 23133 || id_1 < 1)
                {
                    throw illegal_exception();
                }
                else
                {
                    mygraph.deletion(id_1);
                }
            }
            catch (illegal_exception alert)
            {
                cout << alert.msg() << endl;
            }
        }

        //mst function
        else if (command == "mst")
        {
            cin >> id_1;
            mygraph.getMST(id_1);
        }

        //size of vertices
        else if (command == "size")
        {
            mygraph.getSize();
        }

        //empty
        else
        {
            return 0;
        }
    }
}