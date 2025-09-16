#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>


using namespace std;

//Helper funciton to lowercase a string
string toLower(const string & s)
{
    string res = s;
    for(auto& c :res)
    {
        c = tolower(c);
    }
    return res;
}


string maskVowels(const string &s)
{
    string res =s ;
    for(char &c : res)
    {
        char lc = tolower(c);


        if(lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
        {
            c = '*';
        }
        else
        c = lc;

    }
    return res;

}


vector<string> spellchecker(vector<string>& wordList, vector<string>& queries)
{
    unordered_set<string>exact (wordList.begin(), wordList.end());
    unordered_map<string,string>lowerMap;
    unordered_map<string,string>vowelMap;


    for(const string &word : wordlist)
    {
        string low = toLower(word);
        string mask = maskVowels(word);

        if(!lowerMap.count(low))
        {
            lowerMap[low] = word;
        }
        if(!vowelMap.count(mask))
        {
            vowelMap[mask] = word;
            
        }

    }
}

int main()
{
    vector<string>wordlist = {"KiTe","kite","hare","Hare"};
    vector<string>queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    string ans = spellChecker(wordlist,queries);

    for(auto &an : ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;
    
}
