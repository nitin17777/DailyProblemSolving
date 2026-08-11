#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin>>n;

    string s;
    cin>>s;

    set<char>vow = {'a','e','i','o','u','y'};

    string ans = "";
    ans+=s[0];

    for(int i = 1;i<n;i++)
    {
        if(vow.find(s[i-1]) != vow.end())
        {
            if(vow.find(s[i]) == vow.end())ans+=s[i];
        }
        else ans+=s[i];
    }
    cout<<ans<<'\n';

    return 0;
}