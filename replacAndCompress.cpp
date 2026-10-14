#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();

        /*
        
        We can do this operation just once

        Choose any one index from 2 to n-1 and toggle it or not toggle
        replace each maximal block of consecutive equal chars with one such characters

        Determine number of different strings that can be obtained by doing so 
        */

        bool aa = false, aba = false;

        for(int i=1;i+1<n;i++)
        {
            if(s[i-1] == s[i] && s[i] == s[i+1])aa=true;
            else if(s[i-1] != s[i] && s[i]!=s[i+1])aba=true;
        }
        cout<<1+aa+aba<<'\n';   
    }

    return 0;
}