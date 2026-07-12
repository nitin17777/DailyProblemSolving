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

        if(n==2)
        {
            cout<<-1<<'\n';
            return 0;
        }
        //Construct such array : sum is divisible by all elements in the array


        //But each element must be distinct
        // for(int i = 0;i<n;i++)cout<<1<<" ";


        vector<ll>a;
        ll sum = 0;

        for(int i = 1;i<n;i++)
        {
            a.push_back(i);
            sum+=i;
        }

        ll lcmm = 1;

        for(int i = 1;i<=n;i++)
        {
            lcmm = lcm(lcmm,ll(i));
        }


        ll x = 0;
        for (int k = 0;; k++) 
        {
            x = (k+1)*lcmm-sum;

            if (x <= n - 1) continue;

            if (((k + 1)*lcmm) % x == 0) break;
        }

        for(auto& y:a)cout<<y<<" ";

        cout<<endl;
    
    }

    return 0;
}