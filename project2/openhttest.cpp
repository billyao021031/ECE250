#include <iostream>
#include "doublehashentry.hpp"
#include "doublehashbuild.hpp"

using namespace std;

int main()
{

    string command = "";
    hashBuild hashtable;

    while (command != "exit")
    {

        cin >> command;

        //if the command is m, set the size of the hashtable
        if (command == "m")
        {
            int size;
            cin >> size;
            hashtable.setSize(size);
        }

        //if the command is i, insert the entry into the hashtable
        else if (command == "i")
        {
            long long studentNumber;
            string studentName;
            cin >> studentNumber >> studentName;
            hashtable.insertKey(studentNumber, studentName);
        }

        //if the command is s, search for the student last name in the hashtable
        else if (command == "s")
        {
            long long SN;
            cin >> SN;

            hashtable.searchEntry(SN);
        }

        //if the command is d, delete the input entry
        else if (command == "d")
        {
            long long SN;
            cin >> SN;

            hashtable.deleteEntry(SN);
        }
    }
}
