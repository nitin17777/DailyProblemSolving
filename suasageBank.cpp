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

        Deposits 1 dollar in his account
        x = amount in bank in the beginning of the day

        Bank will be open for n days only

        1-> in morning -> x = 2x
        2-> at night, he may withdraw the money and if he do so -> bank reset to 1 dollar, otherwise he leaves the money in bank

        Determine max money he can get out 
        
        */

        if(n-k==0)
        {
            cout<<2*k<<'\n';
            continue;
        }

        int ans = pow(2,n-k+1) + 2*(k-1);
        cout<<ans<<'\n';
    
    }

    return 0;
}