#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<int>&a,int n,int x)
{
    /*

    cost increases daily : 1,2,3....

    x = everyday budget

    How many packs will we be able to buy till the cost exceeds x?
    */

    sort(a.begin(),a.end());

    //Every day cost increases by (n-1)*day

    vector<ll>pref(n);
    pref[0] = a[0];

    for(int i=1;i<n;i++)pref[i] = pref[i-1]+a[i];

    ll ans = 0;

    ll prev = -1;

    for(int i = n;i>=1;i--)
    {
        //If already exceeds -> SKIP
        if(pref[i-1] > x)continue;

        //Last day we can buy i packs
        ll lastDay = (x-pref[i-1])/i;

        ll days = lastDay - prev;

        ans+=days*i;

        prev = lastDay;
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
        int n,x;
        cin>>n>>x;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        cout<<solve(a,n,x)<<'\n';
    
    }

    return 0;
}