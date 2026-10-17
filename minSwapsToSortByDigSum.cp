#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findSum(int num)
{
    int n = num;
    int ans= 0;

    while(n)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}

int minSwaps(vector<int>& nums)
{
    int n = nums.size();

    //We need to sort the array based on the sum of digits of each number ,if both have same sum -> smaller number appears first

    //Return min number of swaps to sort the array in this manner


    //Storing original elements with their indices
    vector<pair<int,int>>arr;
    for(int i = 0;i<n;i++)arr.push_back({nums[i],i});

    sort(arr.begin(),arr.end(), [&](auto&a,auto&b)
    {
        int s1 = findSum(a.first);
        int s2 = findSum(b.first);

        //Return the one with smaller sum first 
        if(s1!=s2)return s1<s2;

        //if tie breaker -> put smaller element first
        return a.first < b.first;
    });

    //vis[i] tells whether element at sorted position i has alreaddy been handled in a cycle 
    vector<bool>vis(n,false);

    int swaps = 0;

    for(int i = 0;i<n;i++)
    {
        if(vis[i] || arr[i].second == i)continue;

        int cycleSize = 0;
        int j =i;

        //Starting to follow the cycle from index i 
        while(!vis[j])
        {
            vis[j] = true;

            //element currently at sorted position j originally came froom index arr[j].second
            j=arr[j].second;
            
            cycleSize++;
        }

        //Cycle of k elements need exactly k-1 swaps
        swaps+=cycleSize-1;
    }
    return swaps;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {37,100};
    cout<<minSwaps(nums)<<'\n';

    return 0;
}