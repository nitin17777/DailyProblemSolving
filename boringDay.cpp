#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int l,int r)
{
    //He takes some cards from top of the deck and finishes the round
    
    //if sum of cards collected during the round is bw l and r inclusive ->orund is won


    //Determine the max number of rounds he can win 


    int n = a.size();
    vector<int>prefix(n+1);

    for(int i = 0;i<n;i++)
    {
        prefix[i+1] = prefix[i] + a[i];
    }


    //as soon as prefix sum goes out of range remove prefix[i-1] from current running chain
    vector<int>dp(n+1);


    // s = current window sum , j = right pointer
    int s = 0,j = -1;
    for(int i = 0;i<n;i++)
    {
        dp[i+1] = max(dp[i+1],dp[i]);

        if(j<i)
        {
            j = i;
            s= 0;
        }

        while(j<n && s<l)
        {
            s+=a[j++];
        }

        if(s>= l && s<=r)
        {
            dp[i] = max(dp[j], dp[i] +1);
        }
        s-=a[i];
    }
    return dp[n];
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;


        vector<int>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,l,r)<<endl;

    }

    return 0;
}




