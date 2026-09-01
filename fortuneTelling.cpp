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
        ll n,x,y;
        cin>>n>>x>>y;

        ll total = 0;
        vector<ll>a(n);
        for(auto& x:a)
        {
            cin>>x;
            total+=x;
        }

        /*We start with some intger d

        Replace: d = ai + d
                d = d XOR ai

        Either alice or bob ended up with number y in the end 

        Find out who could get the number y 

        There can be 2^n possible results in both individually, so it would be very naive to find al these, so we will need an optimised approach to solve this more effeciently
        
        + and XOR behaves identically wrt parity

        x and x+3 will have different parity always,so final parity of answer for both would be different

        Xoring the parity bits == whether final sum is odd or even

        If ai is even -> both parities stays the same
            But if ai is odd ->both parities flips



        */

        if((x+total)%2 == y%2)cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';
    }

    return 0;
}