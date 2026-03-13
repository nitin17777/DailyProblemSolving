#include<bits/stdc++.h>
using namespace std;
#define ll long long


long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
{
    int n = workerTimes.size();

    //Workers work simultaneously to reduce height of the mountain

    //Return the min number of seconds required for workers to make the height of mountain 0


   

    ll low = 0;
    ll high = 1e18;

    ll ans = high;

    auto can = [&](ll T)
    {
        ll removed = 0;

        for(ll w: workerTimes)
         //To reduce the height by x : Time required = wt[i] + wt[i]*2 + wt[i]* 3...wt[i]*x == w[t] * (1+2+3+...x) = w[t]*(x(x+1)/2) <= T 
        //On solving : x = (sqrt(1+4*val) -1)/2

        {
            ll val = (2*T)/w;

            ll x = (sqrt(1+4.0* val) - 1)/2;

            removed+=x;

            if(removed >= mountainHeight)return true;
        }
        return false;
    };

    //Standard bianry search for min valid T
        while(low<=high)
        {
            ll mid = (low+high)/2;

            if(can(mid))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>w = {2,1,1};
    cout<<minNumberOfSeconds(4,w)<<endl;

    return 0;
}