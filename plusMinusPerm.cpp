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

        //Score = sum of indices divisble by x - sum of indices divisile by y
        //Find the max possible score divisible among all permutations of lenght n'

        
        
        ll l = lcm(x,y);

        ll cx = n/x - n/l;
        ll cy = n/y - n/l;

        //So largest cx numbers 

        //Sn​=n​[2a+(n−1)d] / 2
        ll mx = cx* (2LL *n - cx +1)/ 2;

        //Minimum cy numbers
        ll mn = cy *(cy+1)/2;

        cout<<mx-mn<<'\n';

    }
    return 0;
}