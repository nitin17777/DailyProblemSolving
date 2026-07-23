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
        int n;
        cin>>n;

        vector<ll>cnt(31,0);
        for(int i =0;i<n;i++)
        {
            int x;
            cin>>x;

            //since Numbers with same highest set bit always form valid pairs
            cnt[__lg(x)]++;
        }

        //find number of pairs: ai & aj >= ai XOR aj


        //BRUTE FORCE LOL
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if((a[i] &a[j]) >= (a[i]^a[j]))ans++;
        //     }
        // }
        // cout<<ans<<'\n'; 
        
        //if same highest bit -> always true 
        //

        ll ans = 0;
        for(auto& x:cnt)
        {
            ans+= x*(x-1)/2;
        }
        cout<<ans<<'\n';
    }
    return 0;
}