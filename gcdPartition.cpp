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
        vector<ll>a(n);

        for(auto & x:a)cin>>x;

        //split array into k subsegments 
        //Calculate sum of each k subsegment and record these sums in another array b
        // Final score=gcd(array b)

        vector<ll>pref(n);
        pref[0] = a[0];

        for(int i =1;i<n;i++)
        {
            pref[i] = pref[i-1]+a[i];
        }

        ll sum = accumulate(a.begin(),a.end(),0LL);

        //Merging mroe segments will never hurt the gcd, it either increase or remain same


        //there would be only one cut: prefix | sum - prefix

        ll ans = 0;
        //Cut from start till just before the last element
        for(int i = 0;i<n-1;i++)
        {
            ans = max(ans,gcd(pref[i],sum-pref[i]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}