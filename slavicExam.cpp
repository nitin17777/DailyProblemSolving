#include<bits/stdc++.h>
#define ll long long
using namespace std;


string solve(string&s,string&t)
{
    int n = s.size(),m = t.size(); 

    /* Change each ?  to any letter such that string t becomes a subsequence of s
       
    Determine if such s can exist with given constraints , if yes return s else no

    */

    int i = 0,j = 0;
    while(i<n && j<m)
    {   

        if(s[i] == '?' || s[i] == t[j])
        {
            s[i] = t[j];
            i++;
            j++;
        }
        else i++;
    }

    if(j<m)return "NO";

    for(char& c:s)
    {
        if(c=='?')c='a';
    }

    return s;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string n,m;
        cin>>n>>m;


        string ans = solve(n,m);


        if(ans == "NO")cout<<"NO"<<endl;

        else 
        {
            cout<<"YES"<<endl;
            cout<<ans<<endl;
        }
    }

    return 0;
}