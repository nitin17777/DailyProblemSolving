#include<bits/stdc++.h>
#define ll long long
using namespace std;

string smallestPalindrome(string s,int k)
{

    int n = s.size();

    //Better to form all the palindromes, then sort and then finally return the answer

    vector<int>cnt(26,0);

    char mid = '\0';

    for(auto& x:s)cnt[x-'a']++;

    for(auto& x:s)
    {
        if(cnt[x-'a']%2 != 0)
        {
            mid = x-'a';
        }
    }




}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<smallestPalindrome("abba",2)<<endl;

    return 0;
}


