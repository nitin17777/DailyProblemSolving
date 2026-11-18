#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Didnt understood properly
      
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

        vector<int>a(2*n+1);
        for(int i = 1; i <= 2*n; i++)cin >> a[i];

        int score = 0;

        //choose any x that is present in the array

        //l and r =  left and rigthmost occurences of x in the current array 
        //add (r-l+1)^2 to score

        //and then delete elements in this range l..r
        
        //now reindexing will take place too


        //Determine max score

        //Storing first and last occurence of any number


        vector<int>first(n+1,0);

        //dp[i] = max score we can oobtain by partitioning the prefix a[i...i]
        //dp[0] = 0, as empty arrrat has score of 0
        vector<ll>dp(2*n+1,0);

        for(int i = 1; i<=2*n; i++)
        {
            int x = a[i];

            //making position i as singleton
            dp[i] = dp[i-1]+1;


            //make [l...i] once complete block
            if(first[x] != 0)
            {
                int l = first[x];
                ll len = i-l+1;

                ll takePair = dp[l-1]+ len *len;

                dp[i] = max(dp[i],takePair);
            }
            else first[x] = i;
        }
        cout<<dp[2*n]<<'\n';
    }

    return 0;
}