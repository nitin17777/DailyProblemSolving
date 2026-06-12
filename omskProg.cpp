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
        int a,b,x;
        cin>>a>>b>>x;

        /*

        We want to make a and b equal by : 
        Choose a or b and add 1 to it
        choose a or b and divide it by x by rounding of

        Find min ops after which a becomes equal to b
        */

        if(x==1)
        {
            cout<<abs(a-b)<<'\n';
            continue;
        }

       if(a==b)
       {
            cout<<0<<'\n';
            continue;
       }

    //    int diff = abs(a-b);

    //    if(x>=a && x>=b)
    //    {
    //         cout<<min(2,diff)<<'\n';
    //         continue;
    //    }
       
    //    //now at every step we have two choices either divide the bigger number or add 1 to smaller number 

    //    int ops = 0;
    //    while(a!=b)
    //    {
    //         int add = min(a,b) + 1;
    //         int div = max(a,b) / x;

    //         int subAdd = max(a,b) - add;
    //         pair<int,int>subAddP = {max(a,b),add};

    //         int subDiv = div - min(a,b);
    //         pair<int,int>subDivP = {div,min(a,b)};

    //         if(subDiv > subAdd)
    //         {
    //             a = subDivP.first;
    //             b = subDivP.second;
    //         }
    //         else 
    //         {
    //             a = subAddP.first;
    //             b = subAddP.second; 
    //         }
    //         ops++;
    //    }

    //    cout<<ops<<'\n';

    map<ll,ll>dist;

    ll cost = 0,val = a;

    while(true)
    {

        if(!dist.count(val))dist[val] = cost;

        if(val == 0)break;

        val/=x;
        cost++;
    }

    ll ans = LLONG_MAX;

    val = b;
    cost = 0;

    while(true)
    {
        for(auto & [va,costA]:dist)
        {
            ans = min(ans,costA+cost+abs(va - val));
        }

        if(val == 0)break;

        val/=x;
        cost++;
    }
    cout<<ans<<'\n';
    }

    return 0;
}