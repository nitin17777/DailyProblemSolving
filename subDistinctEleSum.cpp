#include<bits/stdc++.h>
#define ll long long
using namespace std;

int sumCounts(vector<int>& nums)
{
    int n = nums.size();

    //Sum of squares of distinct count of alll subarrays of nums
   

    //check window of each size from index i and build a set in that range ->and add in required ans

    ll ans = 0;


    for(int i = 0; i<n;i++)
    {
        unordered_map<int,int>freq;
        int distinct = 0;

        for(int j = i;j<n;j++)
        {
            if(freq[nums[j]] == 0)distinct++;

            freq[nums[j]]++;

            ans+= 1LL * distinct * distinct;
        }
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
    
    }

    return 0;
}