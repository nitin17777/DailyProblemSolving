#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<bool>&vis,int l,int r)
{
    for(int i = l;i<=r;i++)
    {
        if(vis[i] == true)return true;
    }
    return false;
}

void fill(vector<bool>&vis,int l,int r)
{
    for(int i = l;i<=r;i++)vis[i]=true;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x,m;
        cin>>n>>x>>m;

        // vector<bool>vis(n+1,false);

        // vis[x]=true;

        //Initially ax= 1 and all other elements are equal to 0
        //We have to perform 'm' operations 
        //during ith operation -> we can choose any two indices bw li and ri and swap ac and ad

        //after perfromig m operations, how many different indices k could possibly contain 1 

        int L = x,R = x;

        while(m--)
        {
            int l,r;
            cin>>l>>r;

            if(l<=R && r>=L)
            {
                L = min(L,l);
                R = max(R,r);
            }

            //if(check(vis,l,r))fill(vis,l,r);
        }
        cout<<R-L+1<<'\n';
        // ll ans = 0LL;
        // for(auto x:vis)if(x)ans++;
        // cout<<ans<<'\n';
    }

    return 0;
}