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
        int n,k;
        cin>>n>>k;
        /*n spots where they nap

        A -> Changes in dereasing order
        B-> Changes in increasing order

        If they clash -> cat A will take the spot

        Determine the position of B after k hours


        They will clash when n=odd only

        */

        ll ans =0;

        //since they will never clash when n is even
       if(n%2 == 0)
       {
            ans = ((k-1)%n)+1;
       }

       else 
       {
            //otherwise they will clash at n+1 / 2

            ll extra = (k-1)/(n/2);
            ans = ((k-1+extra)%n)+1;
       }
       cout<<ans<<endl;


    }

    return 0;
}