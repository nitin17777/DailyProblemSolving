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
        int n,m;
        cin>>n>>m;

        //Vector containing all initials
        set<char>w;
        for(int i = 0;i<n;i++)
        {
            string x;
            cin>>x;
            w.insert(toupper(x[0]));
        }
        //Set of words
        vector<string>a(m);
        for(auto&x:a)cin>>x;

        bool possible = true;
        for(auto&x:a)
        {
            for(int i = 0;i<x.size();i++)
            {
                if(w.find(x[i]) == w.end())
                {
                    possible=false;
                    break;
                }
            }
        }
        cout<<(possible?"Yes":"No")<<'\n';
    }
    return 0;
}