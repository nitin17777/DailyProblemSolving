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

        /*

        Package of ith type consists of exactly i shovels and the store has exactly k types of packages but infinite number of packages of each type

        Choose one type of packages and then buy several packages of this type


        Determine smallest number of packages he has to buy to get exactly n shovels

        
        */

        ll ans = n;

        //Because if j divides n -> j and n/j are both divisors and one of them must be <= root n
        for(ll i=1;i*i<=n;i++)
        {
            if(n%i==0)//then we have pair: i and n/i
            {
                if(i<=k)
                {
                    ans=min(ans,n/i);
                }

                if(n/i <=k)
                {
                    ans = min(ans,i);
                }
            }
        }
        cout<<ans<<'\n';  
    }
    return 0;
}