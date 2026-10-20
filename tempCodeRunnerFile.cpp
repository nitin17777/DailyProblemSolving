#include<bits/stdc++.h>
#define ll long long
using namespace std;


int numMatchingSubseq(string s, vector<string>& words)
{
    //Return number of words[i] that is subsequence of s

    int n = words.size();

    //Two pointer approach first
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