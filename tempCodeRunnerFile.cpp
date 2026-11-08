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

        vector<int>a(n),b(n);
        for(auto&x:a)cin>>x;
        for(auto&x:b)cin>>x;

        // Special case: only one element
    // There are no subarrays of length >= 2 to constrain it.
    if (n == 1)
    {
        cout << (a[0] > 1 ? 1 : 0) << '\n';
        continue;
    }
    
    int ans=0;

    // First element: only needs to preserve GCD with a[1]
    if (gcd(a[0], a[1]) < a[0])
    {
        ans++;
    }


    // Last element: only needs to preserve GCD with a[n-2]
    if (gcd(a[n - 2], a[n - 1]) < a[n - 1])
    {
        ans++;
    }

    // Check all internal elements
    for (int i = 1; i < n - 1; i++)
    {
        // GCD with left neighbor
        ll g1 = gcd(a[i - 1], a[i]);

        // GCD with right neighbor
        ll g2 = gcd(a[i], a[i + 1]);

        // Smallest value preserving both adjacent GCDs
        ll smallest = lcm(g1, g2);

        // We must strictly decrease the original element
        if (smallest < a[i])ans++;
    }
    cout<<ans<<'\n';
    }

    return 0;
}