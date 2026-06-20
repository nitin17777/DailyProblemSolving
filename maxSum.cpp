#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(vector<ll>&a,ll n,ll k)
{

    //We have exactly k operations 
    //Ops: Find two min elements in the array and delete them
        // Find max element in the array and delete it


    //Find max possible sum of elements in the final array


    sort(a.begin()+1,a.end());

    // 1 2 5 6 10


    // check whether last 


    vector<ll>pref(n+1,0);

    for(int i=1;i<=n;i++)
    {
        pref[i] = pref[i-1]+a[i];
    }

    ll ans = 0;


    for(int m=0;m<=k;m++)
    {
        //Left boundary after removing first 2 elements
        int L = 2*m+1;

        //Right boundary after removing 2*m smallest elements
        int R = n-(k-m);

        ll sum = pref[R]-pref[L-1];

        ans = max(ans,sum);
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        vector<ll>a(n+1);

        for (int i = 1; i <= n; i++)cin >> a[i];

        cout<<solve(a,n,k)<<'\n';    
    }
    return 0;
}