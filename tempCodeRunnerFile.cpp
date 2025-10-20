#include<iostream>
#include<vector>
using namespace std;



int minStartValue(vector<int>& nums)
{
    int n = nums.size();
    vector<int>prefixSum(n);
    prefixSum[0] = nums[0];
    for(int i = 1;i<n;i++)
    {
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    int start = nums[0];

    for(int i = 0; i < n;i++)
    {
        if(start+nums[i] < 1)start++;
    }

    return start;

}

/*
int minStartValue(vector<int>& nums)
{
    //start with any value you want  

    //which start value will be such that sum at none of the step would be less than 1

    int n = nums.size();
    int negative = 0, positive =0;

    // for(int i =0 ;i <n;i++)
    // {
    //     if(nums[i] < 0)
    //     {
    //         negative +=nums[i];
    //     }
    //     else
    //     {
    //         positive+=nums[i];
    //     }
    // }

    // if(negative < positive)return 1;

    int start = nums[0]+1;

    
    int i = 0;
   // for(int i = start;i<100;i++)
   while(i<n)
    {
        start+=nums[i];

        if(start<1)
        start++; 
        
        else i++;
    }
    return start;


}
*/


int main()
{
    vector<int>nums = {-3,2,-3,4,2};
    cout<<minStartValue(nums)<<endl;

    return 0;
    
}
