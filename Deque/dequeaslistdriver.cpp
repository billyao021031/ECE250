#include <iostream>
#include <string>
#include "deque.hpp"
#include "node.hpp"

using namespace std;

int main()
{
    std::string instruction;

    bool lineBreak = cin.eof(); // validate if the line input ends

    while (!lineBreak)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    {

        getline(cin, instruction);
        deque queue;

        if (instruction.substr(0, 1) == "m")
        {
            int max_entry = stoi(instruction.substr(2, string::npos));
            queue.setQueue(max_entry);

            string uName;
            string uLink;

            while (getline(cin, instruction))
            {
                if (instruction.substr(0, 10) == "push_front")
                {
                    uName = instruction.substr(11, instruction.find(" ", 11) - 11);
                    uLink = instruction.substr(instruction.find(" ", 11) + 1, string::npos);
                    queue.push_front(uName, uLink);
                }
                else if (instruction.substr(0, 9) == "push_back")
                {
                    uName = instruction.substr(10, instruction.find(" ", 10) - 10);
                    uLink = instruction.substr(instruction.find(" ", 10) + 1, string::npos);
                    queue.push_back(uName, uLink);
                }
                else if (instruction.substr(0, 9) == "pop_front")
                {
                    queue.pop_front();
                }
                else if (instruction.substr(0, 8) == "pop_back")
                {
                    queue.pop_back();
                }
                else if (instruction == "clear")
                {
                    queue.clear();
                    cout << "success" << endl;
                }
                else if (instruction == "size")
                {
                    queue.size();
                }
                else if (instruction == "front")
                {
                    queue.front();
                }
                else if (instruction == "back")
                {
                    queue.back();
                }
                else if (instruction == "empty")
                {
                    queue.empty();
                    if(queue.empty() == true){
                        cout << "empty 1" << endl;
                    }else{
                        cout << "empty 0" << endl;
                    }
                }
                else if (instruction.substr(0, 4) == "find")
                {
                    uName = instruction.substr(5, string::npos);
                    queue.findName(uName);
                }
                else if (instruction.substr(0, 5) == "print")
                {
                    queue.print();
                }
                else if (instruction == "exit")
                {
                    queue.~deque();
                    return 0;
                }
            }
        }
    }
}