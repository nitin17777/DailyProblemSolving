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
        int a,b,k;
        cin>>a>>b>>k;

        vector<int>boys(k),girls(k);
        
        for(auto & x:boys)cin>>x;
        for(auto & x:girls)cin>>x;

        /*

        Each class must present 2 couples to the ball

        No person should be there in more than 1 pair

        //Find 2 pairs such that boys
        
        */

        vector<ll>bCnt(a+1,0);
        vector<ll>gCnt(b+1,0);

        for(int x:boys)bCnt[x]++;
        for(int x:girls)gCnt[x]++;

        ll ans = 0;

        for(int i = 0;i<k;i++)
        {
            ans += (k-i-1) - (bCnt[boys[i]]-1) - (gCnt[girls[i]] - 1);

            bCnt[boys[i]]--;
            gCnt[girls[i]]--;
        }
        cout<<ans<<'\n';
    }

    return 0;
}