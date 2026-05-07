#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> maxValue(vector<int>& nums)
{

    int n = nums.size();

    /*

    jump foward if nums[j] < nums[i]: you will get smaller value

    Jump backward if nums[i] < nums[j]: backward and greater value

    For each index i find max value in nums which can be reached

    ans[i] = mamx value reachable starting from index i

    From last number find the largest number before it

    */

    vector<int>prefixMax(n);
    prefixMax[0] = nums[0];

    for(int i = 1;i<n;i++)
    {
        prefixMax[i] = max(prefixMax[i-1],nums[i]);
    }

    vector<int>suffixMin(n);
    suffixMin[n-1] = nums[n-1];

    for(int i = n-2;i>=0;i--)
    {
        suffixMin[i] = min(suffixMin[i+1],nums[i]);
    }

    //Tow regions are disconnected only when max(left) < min(right)

    vector<int>ans(n);

    int start = 0;

    for(int i = 0;i<n-1;i++)
    {
        //Because we can jump to bigger values if they are in left side
        if(prefixMax[i] <= suffixMin[i+1])
        {
            int mx = prefixMax[i];

            for(int j = start;j<=i;j++)
            {
                ans[j] = mx;
            }
            start = i+1;
        }
    }

    int mx = prefixMax[n-1];
    for(int j = start;j<n;j++)ans[j]=mx;

    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {2,1,3};
    vector<int>ans = maxValue(nums);

    for(auto&x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}