#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxDistance(vector<int>& nums)
{
    int n = nums.size();

    //Return the farthest distance bw 2 numbers

    int maxi = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = n-1;j>=0;j--)
        {
            if(nums[i] != nums[j])
            {
                maxi = max(maxi,abs(i-j));
            }
        }
    }
    return maxi;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,1,1,6,1,1,1};
    cout<<maxDistance(nums)<<endl;
    
    return 0;
}