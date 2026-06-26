#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Cf predicted rating = 2.2k
//COPIED THE EDITORIAL SOLUTION,DIDN'T UNDERSTOOD THE APPROACH MUCH
long long countMajoritySubarrays(vector<int>& nums, int target)
{
    int n = nums.size();

    //pre[i] = how many previous prefix sums are equal to i-n
    vector<int>pre(n*2+1,0);
    pre[n] = 1;
    int cnt = n;

    ll ans = 0,preSum=0;

    
    //Target is the majority element iff sum of this new array is greater than 0

    for(int i = 0;i<n;i++)
    {
        if(nums[i] == target)
        {

            //If current element is target -> trasnformed value +=1
            preSum+=pre[cnt];

            cnt++;

            pre[cnt]++;
        }

        else
        {
            cnt--;

            preSum-=pre[cnt];
            pre[cnt]++;
        }
        ans+=preSum;
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,2,2,3};
    cout<<countMajoritySubarrays(nums,2)<<'\n';


    return 0;
}