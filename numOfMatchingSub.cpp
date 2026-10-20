#include<bits/stdc++.h>
#define ll long long
using namespace std;




int numMatchingSubseq(string s, vector<string>& words)
{
    //Waiting[c] = stores words currently waiting for char c : wordIndex, next character position to match c
    vector<pair<int,int>>waiting[26];

    int ans = 0;

    //As initially every word waits for it's first char
    for(int i = 0;i<words.size();i++)
    {
        if(words[i].empty())ans++;

        else  waiting[words[i][0]-'a'].push_back({i,0});
    }

    //Process each char of exactly once 
    for(char c:s)
    {
        //processing only words waiting for c
        auto curr = move(waiting[c-'a']);//Just a method to safely move and free up their bucket so they can be used again effeciently

        for(auto[wordIdx,pos]: curr)
        {
            //since we have matched the current character
            pos++;

            //If this char matched ->this word is the subsequnece
            if(pos = words[wordIdx].size())ans++;

            else
            {
                //else wait for next char in this word
                char nextChar = words[wordIdx][pos];
                waiting[nextChar-'a'].push_back({wordIdx,pos});
            }
        }
    }
    return ans;
}


 //Two pointer approach first
int numMatchingSubseq1(string s, vector<string>& words)
{
    //Return number of words[i] that is subsequence of s


    int ans = 0;

    for(string&word:words)
    {
        int i = 0,j=0;

        while(i<s.size() && j <word.size())
        {
            if(s[i] == word[j])j++;

            i++;            
        }
        if(j == word.size())ans++;
    }
    return ans;    
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>words = {"a","bb","acd","ace"};
    cout<<numMatchingSubseq("abcde",words)<<endl;


    return 0;
}