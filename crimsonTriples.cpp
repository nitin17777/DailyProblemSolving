#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll n)
{
    //gcd(lcm(a,b), lcm(b,c)) = gcd(a,c)

    //find the number of triplets satisfying this conditiion
    //gcd of a,c must be multiple of b...........


    ll ans = 0;

    for(int b = 1;b<=n;b++)
    {
        ll cnt = n/b;//Multiples of b in given range

        ans += cnt* cnt;
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
        ll n;
        cin>>n;

        cout<<solve(n)<<'\n';    
    }

    return 0;
}