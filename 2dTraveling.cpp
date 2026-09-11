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
        int n,k,a,b;
        cin>>n>>k>>a>>b;


        //we can either fly directly to our destination or go by visiting each city

        //First k cities are considered as major cities


        //Find min cost of all air tickets if he can take any number of flight

        vector<pair<int,int>>city(n+1);
        for(auto &x:city)
        {
            cin>>x.first;
            cin>>x.second;
        }
       
    }

    return 0;
}