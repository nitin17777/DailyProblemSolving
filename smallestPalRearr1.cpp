#include<bits/stdc++.h>
#define ll long long
using namespace std;

string smallestPalindrome(string s)
{
    int n = s.size();

    //We have to return the lexicorgraphically smallest palindrome of s

    if(n<=2)return s;

    vector<int>freq(26,0);
    for(auto & x:s)freq[x-'a']++;

    string left="";
    char mid ='\0';//null char currently

    for(int i = 0;i<26;i++)
    {
        left+=string(freq[i]/2, 'a'+i);

        if(freq[i]%2!=0)mid = 'a'+i;
    }

    string right = left;

    reverse(right.begin(),right.end());

    if(mid)return left+mid+right;

    else return left+right;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<smallestPalindrome("babab")<<endl;


    return 0;
}