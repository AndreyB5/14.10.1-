#include "Trie.h"
#include <iostream>

using namespace std;

TrieNode::~TrieNode()
{
    TrieNode* node;
    while (root != nullptr)
    {
        node = root;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i] != nullptr and isEmpty(node->children[i])) delete node->children[i];
            else if (node->children[i] != nullptr) node = node->children[i];
        }
        delete node;
    }
}

void TrieNode::insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index]) node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool TrieNode::search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool TrieNode::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* TrieNode::remove(TrieNode* root, string key, int depth)
{
    if (!root)
        return nullptr;

    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    return root;
}

void TrieNode::showVariants(TrieNode* root, std::string key)
{
    TrieNode* node = root;
    std::string res = key;
    int size = key.size();

    for (int i = 0; i < size; i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index]) return;

        node = node->children[index];
    }

    if (!node->isEndOfWord and !isEmpty(node))
    {
        cout << "Вероятно Вы имели ввиду:" << endl;
        TrieNode::T9(node, res);
        cout << endl;
    }
}

void TrieNode::T9(TrieNode* root, std::string result)
{
    TrieNode* node = root;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i])
        {
            result.push_back(i + 'a');
            if (node->children[i]->isEndOfWord)
            {
                for (int j = 0; j < result.size(); j++)
                    cout << result[j];
                cout << endl;
            }
            T9(node->children[i], result);
            result.pop_back();
        }
    }
}

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}