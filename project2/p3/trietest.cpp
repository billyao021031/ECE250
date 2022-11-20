#include <iostream>
#include <string>
#include "trie.cpp"
#include <fstream>

int main(){

    std::string cmd = "";
    trie mytrie;

    while(cmd != "exit"){

        std::cin >> cmd;

        if(cmd == "i")
        {
            std::string word;
            std::cin >> word;
            bool a = mytrie.is_find(word);
            if(a == true)
            {
                std::cout << "failure" << std::endl;
            } else {
                mytrie.addword(word);
                std::cout << "success" << std::endl;
            }
            
        }

        else if(cmd == "s")
        {
            std::string word;
            std::cin >> word;
            bool a = mytrie.is_find(word);
            if(a == true)
            {
                std::cout << "found word"<< std::endl;
            } else {
                std::cout << "not found" << std::endl;
            }
        }

        else if(cmd == "empty")
        {   
            mytrie.empty();

        }

        else if(cmd == "p")
        {
            mytrie.print();
        }

        else if(cmd == "e")
        {
            std::string word;
            std::cin >> word;
            bool a = mytrie.is_find(word);
            if(a == true)
            {
                mytrie.erase(word);
                
            } else {
                std::cout << "failure" << std::endl;
            }
        }
    }

return 0;
}