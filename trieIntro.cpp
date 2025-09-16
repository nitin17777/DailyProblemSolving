#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];

    bool isTerminal; //marks the end of a valid word

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i<26;i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:

    TrieNode * root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode * root, string word)
    {

        //base case: when the word is fully processed
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //Assuming that word will be in caps
        int index = word[0] - 'a';
        TrieNode * child;

        //present
        if(root -> children[index] != NULL)
        {
            child = root ->children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[0]);
            root ->children[index] = child;
        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    } 

    bool searchUtil(TrieNode * root , string word)
    {
        if(word.length() == 0)
        {
            return root ->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode * child ;

        //present
        if(root -> children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        //recursion
        return searchUtil(root,word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }

};

int main()
{
    Trie *t = new Trie();

    t->insertWord("abcd");

    cout<<"Present or Not "<<t->searchWord("abcd") << endl;

    return 0;

}