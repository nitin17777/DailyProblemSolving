#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<vector<ll>>&a,int n)
{
    /*

    Stable = a<b<c

    Circular conveyor is there

    Count the number of suitable combos of parameters



    WE have 3*n 2d array, we have to find the number of combos satisfiying : Every row has greater element than previous one

    */


    vector<vector<ll>>dp(3,vector<ll>(n,0));

    //When we stat a sequence from any element from top row, it contributes 1 way
    for(int j = 0;j<n;j++)dp[0][j] = 1;


    // Processing row 1 and row 2
    for(int r = 1;r<3;r++)
    {
        //Current column in that row r
        for(int j = 0;j<n;j++)
        {
            ll ways = 0;

            for(int k = 0;k<j;k++)
            {
                if(a[r-1][k] < a[r][j])ways+=dp[r-1][k];
            }
            dp[r][j] = ways;
        }
    }

    ll ans = 0;
    for(int j=0; j<n;j++)
    {
        ans +=dp[2][j];
    }
    return ans;
}

      
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

        vector<vector<ll>>a(3,vector<ll>(n));

        for(auto &row :a)
        {
            for(auto &x:row)cin>>x;
        }
        cout<<solve(a,n)<<endl;
    }
    return 0;
}