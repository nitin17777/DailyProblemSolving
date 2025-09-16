#include<iostream>
#include <vector>
using namespace std;

class TrieNode
{
    public: 

    char data;
    TrieNode * children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
    
        for(int i = 0; i<26; i++)
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
    
    
    void insertWord(string word)
    {
        TrieNode* curr = root;


        for(char ch: word)
        {
            int index = ch - 'a';

            if(curr ->children[index] == NULL)
            {
                curr->children[index] = new TrieNode(ch);
            }
            
            curr = curr ->children[index];
        }
        curr -> isTerminal = true; // to indicate that this node is the end of the valid word
    }


    void printSuggestions(TrieNode * curr, vector<string>& temp,string prefix)
    {

        //prefix: the string formed so far 
        //temp: vector that will store all suggestions

        if(curr ->isTerminal) // if current node marks the end of the valid word, we add prefix to the result list i.e temp
        temp.push_back(prefix);

        for(char ch ='a'; ch <= 'z'; ch++)
        {
            TrieNode * next = curr ->children[ch - 'a'];
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp,prefix);

                prefix.pop_back();

            }
        }
    }

    vector<vector<string>>getSuggestions(string str)
    {
        TrieNode * prev = root;
        vector<vector<string>>output;
        string prefix = "";

        for(int i = 0 ; i<str.length(); i++)
        {   
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode* curr = prev->children[lastch - 'a'];
            if(curr == NULL)
            break;
        
        vector<string>temp;
        printSuggestions(curr,temp,prefix);
        output.push_back(temp);

        prev=curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList,string &queryStr)
{
    //creation of trie
    Trie * t = new Trie();

    //insert all elements in trie
    for(int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];

        t->insertWord(str);

    }
    return t-> getSuggestions(queryStr);
}


int main()
{
    vector<string>contactList = {"coding" , "code" , "coder", "codex" , "cool" ,  "cat"};

    string queryStr = "cod";

    vector<vector<string>>result = phoneDirectory(contactList,queryStr);

    int level = 1;
    for(auto suggestions: result)
    {
        cout<<"Suggestions for \" "<< queryStr.substr(0,level++) << "\": "<<endl;
        for(auto word : suggestions)
        {
            cout<<word<<" ";
        }
        cout<<endl;
        cout<<endl;
    }
    
    cout<<endl;
    return 0;
}
