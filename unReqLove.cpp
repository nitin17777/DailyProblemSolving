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

        vector<int>even,odd;
        vector<int>a(n);
        for(auto&x:a)cin>>x;

        /*
        
        n keys are there giving a1, a2.... units of audience love


        Triad brings : love of x , x+2, x+4

        Determine the number of ways to choose two such triads such that both have same love  
        */

        vector<ll>sum(n-4);

      for(int i = 0; i <= n - 5; i++)
        {
            sum[i] = a[i] + a[i+2] + a[i+4];
        }

        // cnt[x] = number of previous triads having sum x
        unordered_map<ll, ll> cnt;
        ll ans = 0;

        for(int i = 0; i <= n - 5; i++)
        {
            // All previous triads with the same sum
            ans += cnt[sum[i]];

            // Triad i overlaps with triad i-2
            if(i >= 2 && sum[i-2] == sum[i])
                ans--;

            // Triad i overlaps with triad i-4
            if(i >= 4 && sum[i-4] == sum[i])
                ans--;

            cnt[sum[i]]++;
        }
        cout << ans << '\n';
    }

    return 0;
}