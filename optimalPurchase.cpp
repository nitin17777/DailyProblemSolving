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
        ll n,a,b;
        cin>>n>>a>>b;

        //min amount of money needed for n students

        bool bless = true;

        ll ans = 0;
        bless = 3*a > b;

        if(b>=3*a)cout<<n*a<<endl;

        else
        {
            ll groups = n/3;
            ll rem = n%3;

            cout<<groups * b + min(rem*a,b)<<'\n';
        }
    }

    return 0;
}