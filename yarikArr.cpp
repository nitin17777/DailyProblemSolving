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

        vector<int>a(n);
        for(auto& x:a)cin>>x;


        /*

        Elements of chosen subarray must have consecutive different parity
        
        Find the max sum of such subarray

        */



                    // TLE //
    
        // int ans = INT_MIN;
        // for(int i = 0;i<n;i++)
        // {
        //     int sum = a[i];

        //     bool parity = (a[i]%2==0);
        //     ans = max(ans,sum);

        //     for(int j=i+1;j<n;j++)
        //     {
        //         bool currPar = (a[j]%2 == 0);
        //         if(parity!=currPar)
        //         {
        //             sum+=a[j];
        //             parity = currPar;
        //             ans = max(ans,sum);
        //         }
        //         else break;
        //     }
            
        // }

        int ans = a[0];
        int curr = a[0];

        for(int i=1;i<n;i++)
        {
            if((abs(a[i]%2))!=(abs(a[i-1])%2))
            {
                //Decide whether we should include this current element or not as negatives are also there
                curr = max(a[i],curr+a[i]);
            }
            else curr = a[i];

            ans = max(ans,curr);
        }
        cout<<ans<<'\n';
    }

    return 0;
}