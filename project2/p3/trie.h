#include <iostream>
#include <string>
const int size = 26;

class node{

    private:

    friend class trie;
    node *child[size];
    node *parent;
    std::string letter;
    bool isWordEnd;
    bool is_push;

    public:

    node();
    ~node();
};

class trie{

    private:

    int count;
    node *root;


    public:
    
    trie();
    ~trie();

    bool is_find(std::string word);
    
    void addword(std::string word);

    void print();

    void r_print( node *p, std::string word);

    int is_empty(node *p);

    void empty();

    void erase(std::string word);

    void r_erase(node *p, std::string word, int iw);
    
};