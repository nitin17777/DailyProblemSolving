#include<bits/stdc++.h>
#define ll long long
using namespace std;

//to find max length of array possible when the cost limit is x
ll getLen(ll x)
{
    ll len=0;

    for(ll i = 1;i<=x;i++)len += (x/i);

    return len;
}
      
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

        ll low = 0, high = 1;
        while (getLen(high) < n)high *= 2;

        while(low < high)
        {
            ll mid = low + (high-low)/2;

            if(getLen(mid) >= n)high = mid;
            else low = mid+1;
        }


        cout<<low<<endl;
        ///We have the min feasible cost now 
        ll x = low;

        vector<ll>a;
        a.reserve(n);

        for(ll i = 1; i<=x && (int)a.size() < n; i++)
        {
            ll cnt = x/i;

            while(cnt-- && (int)a.size() < n)a.push_back(i);
        }

        for(int i=0;i<n;i++)cout << a[i] << " ";
        cout<<'\n';
    }
    return 0;
}