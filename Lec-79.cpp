// Trie: Data structure similiar like tree
// Here we implement a dictionary and its operation like: Insert/delete/Search.
// T.C. of Insertion: O(l), where l= length of word
// T.C. of Search: O(l), where l= length of word
// T.C. of Removal: O(l), where l= length of word
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    // Each node carry 3 information: data = character, children array , is it terminal node or not
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assumption : words are only consist capital letters
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    // Insert only capital Letters
    t->insertWord("JAI");
    t->insertWord("WIND");
    t->insertWord("INDIA");
    t->insertWord("INDIGO");
    cout << "Is INDIA present or not: " << t->searchWord("INDIA") << endl;
    cout << "Is IND present or not: " << t->searchWord("IND") << endl;

    return 0;
}