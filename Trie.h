#pragma once
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
    ~TrieNode();
    TrieNode* root;
    class TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    void insert(TrieNode*, string);
    bool search(TrieNode*, string);
    bool isEmpty(TrieNode*);
    TrieNode* remove(TrieNode*, string, int depth = 0);
    void showVariants(TrieNode* root, std::string key);
    void T9(TrieNode* root, std::string result);
};

TrieNode * getNewNode(void); 