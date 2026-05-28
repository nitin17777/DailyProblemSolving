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
        int n;
        cin>>n;

        string s;
        cin>>s;




        /*Alice moves first

        In one move player can choose a sequence of indices such that trhey are non increasing and can rearrange to make the sequence non decreasing 


        Select a decreasing(stirctly) subsequence and sort it to make it non decreasing , the first player to not make a move loses


        */


        string t = s;
        sort(t.begin(),t.end());

        if(s==t)
        {
            cout<<"Bob"<<endl;
            continue;
        }

        vector<int>idx;
        for(int i =0;i<n;i++)
        {
            if(s[i] != t[i])idx.push_back(i+1);
        }

        cout<<"Alice"<<endl;
        cout<<idx.size()<<endl;
        for(auto & x:idx)cout<<x<<" ";

        cout<<endl;
    }

    return 0;
}