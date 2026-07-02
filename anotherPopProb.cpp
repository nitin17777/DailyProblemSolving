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
        ll n,k;
        cin>>n>>k;

        //Summation of elements <= n

        //We need max popCount, 

        int ans = 0;
        for(int i=0;i<31;i++)
        {

            ll val = 1LL << i;
            ll take = min(k, n/val);

            ans+=take;
            n-= (take * val);
        }
        cout<<ans<<'\n';
    }
    return 0;
}