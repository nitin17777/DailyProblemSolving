#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    //find the subarray having max product
    int maxProd=nums[0],minProd =nums[0],ans = nums[0];
    int n = nums.size();
    

    for(int i = 1;i<n;i++)
    {
        int temp = maxProd;//storing previous maxProd becasue it will be overwritten later on
        

        maxProd = max({nums[i], nums[i] * maxProd, nums[i] * minProd});

        //needed because a small negative product can later become a large possible number
        minProd = min({nums[i] , nums[i] * temp, nums[i] * minProd});
        ans = max(ans,maxProd);
    }
    return ans;
}


int main()
{
    vector<int>nums = {2,3,-2,4};
    cout<<maxProduct(nums)<<endl;

    return 0;

}