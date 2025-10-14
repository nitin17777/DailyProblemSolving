#include <bits/stdc++.h>
using namespace std;

bool areAnagrams(string w1, string w2)
{
    // avoiding the use of two hash maps
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    return w1 == w2;

    /*
    unordered_map<char,int>f1,f2;

    for(auto&w : w1)
    {
        f1[w]++;
    }

    for(auto&w : w2)
    {
        f2[w]++;
    }

    if(f1 == f2)return true;
    else return false;
    */
}

vector<string> removeAnagrams(vector<string> &words)
{
    // anagram : consists of all the same letters

    // in each loop simply compare the hash table of both words[i] and words[i-1], if same, delete words[i]

    // loop until no CONSECUTIVE anagrams are left
    int i = 1;

    while (i < words.size())
    {
        if (areAnagrams(words[i], words[i - 1]))
        {
            words.erase(words.begin() + i);
        }
        else
        {
            i++;
        }
    }
    return words;
}

int main()
{
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> ans = removeAnagrams(words);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;
    return 0;
}