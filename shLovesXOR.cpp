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
        ll x;
        ll m;
        cin>>x>>m;

        ll ans = 0;
        //Case 1 : x^y is divisible by x 

        //Largest multiple of x that is <=m
        ll p = m-m%x;
        
        //Count gauaranteed multiples (<=m-x)
        ans += p/x - (x<p);

        //checking largest multiple <= m
        ll y = x^p;
        if(y>=1 && y<=m)ans++;

        //check the next multiple of x
        p+=x;
        y = x^p;
        if(y>=1 && y<=m)ans++;


        //Case 2 : x^y is divisible by y
        for(ll y = 1;y<=min(x,m);y++)
        {
            if((x^y) %y == 0)ans++;
        }

        //Case 3: Removing those which are counted in both cases
        if(x<=m)ans--;

        cout<<ans<<'\n';
    }
    return 0;
}