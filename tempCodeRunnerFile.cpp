#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int>solve(vector<int>&nums)
{
    int n = nums.size();
    //if two even nums are there, return them
    for(int i= 0;i< n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            int rem = nums[j] %nums[i];
            if(rem%2 ==0)
            {
                return {nums[i], nums[j]};
                
            }
        }
    }
    return {-1};
}

int32_t main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;cin>>n;

        vector<int>nums(n);
        for(auto&x: nums)cin>>x;

        //Find such pair such that x<y and y%x == is an even number, else return -1

        vector<int>ans = solve(nums);
        for(auto&an:ans)cout<<an<<" ";

        cout<<endl;
    }
    return 0;
}
