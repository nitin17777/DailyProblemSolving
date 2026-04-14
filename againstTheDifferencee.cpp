#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>&a,int n)
{
    //dp[i] = longest neat subsequence using first i elements

    vector<int>dp(n+1,0);

    //Storing all occurence positions of each value
    unordered_map<int,vector<int>>pos;

    for(int i = 1;i<=n;i++)
    {
        int val = a[i-1];

        dp[i] = dp[i-1];

        pos[val].push_back(i);
        int sz = pos[val].size();

        if(sz >= val)
        {
            // starting index of last valid block
            int x = pos[val][sz - val];

            // take this block
            dp[i] = max(dp[i], dp[x - 1] + val);
        }
    }

    return dp[n];

}

/*
int solve(vector<int>&a,int n)
{
    if(a.empty())return 0;

    //block = all elements in array equals the size of array


    //An array is called neat : It can be obtained by concatenation of an arbitrary number of blocks 

    //Find the length of longest neat subsequence
    unordered_map<int,int>freq;
    for(auto &x:a)freq[x]++;

    int ans = 0;
    for(auto & x:freq)
    {
        int num = x.first;
        int cnt = x.second;

        if(cnt >= num)
        {
            int blocks = cnt/num;
            ans+= blocks*num;
        }
    }
    return ans;

}
    */

      
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
        cout<<solve(a,n)<<endl;
    }

    return 0;
}