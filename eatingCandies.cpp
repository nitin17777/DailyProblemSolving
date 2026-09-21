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
        
        ith candy has ai weight

        She can eat any number of candies form left to right and eats them in a row and BOB can do so from right

        Goal is to eat same amount of candies
        Determine max number of candies they can eat
        */

        // vector<int>pref(n),suff(n);

        // pref[0] = a[0];
        // suff[0] = a[n-1];

        // for(int i=1;i<n;i++)
        // {
        //     suff[i] = suff[i-1]+a[i];

        //     pref[n-i-1]= pref[n-i]+a[n-i-1];
        // }

        // //Now check index at which both suffix and prefix become equal

        // //Return 0 if it is impossible to do so

        
        // int ans=INT_MAX;
        // for(int i = 0;i<n;i++)
        // {
        //     for(int j = 0;j<n;j++)
        //     {

        //         if(pref[i]==suff[j])
        //         {
        //             ans = min(abs(i-n-j),ans);
        //         }
        //     }
        // }

        // cout<<ans<<'\n';

        int l = 0,r=n-1;

        int lSum = 0,rSum = 0,ans = 0;

        while(l<=r)
        {
            if(lSum <= rSum)
            {
                lSum +=a[l];
                l++;
            }
            else 
            {
                rSum+=a[r];
                r--;
            }

            if(lSum == rSum)
            {
                int alice = l;
                int bob = n-1-r;
                ans = max(ans,alice+bob);
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}


// 1  2   3   4  5  6
// 2  3   7   9  13 14
// 14 12  11  7  5  1