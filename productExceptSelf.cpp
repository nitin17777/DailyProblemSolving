#include<iostream>
#include<vector>
using namespace std;


    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        
        //created an answer array of size n which is initiallised with 1

        //left to right first :
        vector<int>answer(n,1);

        for(int i = 1; i < n;i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        //right to left

        int suffix = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }

int main()
{
    vector<int>nums = {-1,1,0,-3,3};
    vector<int>ans = productExceptSelf(nums);

    for(auto ele : ans)
    {
        cout<< ele <<" ";
    }
    cout<<endl;
    
    return 0;
}
