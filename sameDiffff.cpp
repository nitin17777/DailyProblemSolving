#include<bits/stdc++.h>
#define int long long
using namespace std;

      
int32_t main()
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
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
            a[i] = a[i]-i+1;
        }

        /*

        Count such pairs
        (i<j) : aj - ai == j-i => aj - j = ai - i
        */
        //Now find such pairs : j>i and aj > ai


        int ans = 0;
        // 2 3 -2 0 1 0
        unordered_map<int,int>freq;
        for(auto&x:a)freq[x]++;

        for(auto &x:freq)
        {
            int f = x.second;

            if(f>1)ans +=  1LL * f*(f-1)/2;
        }
        cout<<ans<<'\n';
    }
    return 0;
}