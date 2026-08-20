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

        vector<int>a(n);
        for(auto& x:a)cin>>x;
         
        //we want to build n-1 two way roads such that all distrcits are reachable from each other using intermediate ways too


        //Two districts beloning to same gang are connected directly with road, the gang will revolt

        vector<pair<int,int>>res;

        int idx = -1;
        //Connecting every different gang district to district 1
        for(int i = 1;i<n;i++)
        {
            if(a[i]!=a[0])
            {
                idx = i;res.push_back({1,i+1});
            }
        }

        if(idx == -1)
        {
            cout<<"No"<<endl;
            continue;
        }

        for(int i = 1;i<n;i++)
        {
            if(a[i] == a[0])
            {
                res.push_back({idx+1,i+1});
            }
        }
        cout<<"Yes"<<endl;
        for(auto[x,y]:res)cout<<x<<" "<<y<<endl;
    }
    return 0;
}