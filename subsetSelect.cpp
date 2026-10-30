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
        int n,k;
        cin>>n>>k;


        vector<int>cnt(n+2,0);

        vector<int>a(n);
        for(auto&x:a)
        {
            cin>>x;
            cnt[x]++;
        }

        int pref = 0;
        int ans = 0;
        for (int v = 0; v <= n; v++)
        {
            pref += cnt[v];
            if(cnt[v] >= 1 && pref >= k * (v + 1))ans = v + 1;
            
            else break;
        }
        cout<<ans<<'\n';
    }

        //Each group contains atleast k elements 

        //Find max possible value of mex(max(s1),max(s2),max(sm))


        //Simply find the mex
        //We want our partition to cover each numnber from 0 onwards
        //sort(a.begin(),a.end());

    return 0;
}