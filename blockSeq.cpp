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
        for(auto&x:a)cin>>x;


        /*

        A sequence is beautiful if it has the form of series of blocks such that first comes the length of block and then it's elements


        In one operation -> We can remove any element from the sequence 
        Find min ops to make the given sequence beautiful

        Format: block size | block itself

        */

        vector<int>dp(n,n+1);

        //dp[i] = number of ops to make segment from i to n beautiful
        // 1-> Remove the element at i and make segment :i+1 to n beautiful
        //2-> Make the segment from i+ai+1 to n beautiful =>Then dp[i] = dp[i+ai+1], boundary case issues needs to be handled with care 

        //Remove the last element
        dp[n-1]=1;


        //Working backwards for this dp 
        for(int i = n-2; i>=0; i--)
        {

            //Option 1-> Remove a[i]
            int remove = dp[i+1]+1;

            //Option 2-> Keep a[i] and jump to i + a[i]+1;

            int next = i+a[i]+1;
            int keep;

            if(next > n)
            {
                keep=n+1;
            }
            else if(next==n)
            {
                keep=0;
            }

            else keep=dp[next];
        
            dp[i]=min(remove,keep);
        }
        cout<<dp[0]<<'\n';    
    }
    return 0;
}