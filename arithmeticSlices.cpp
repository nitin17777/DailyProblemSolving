#include<bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& nums)
{
    ////atleast 3 elements and if difference bw any two consecutive elements is same

    int n = nums.size();

    if(n<3)return 0;

    int total = 0;
    int count = 0;

    for(int i = 2;i<n;i
        ++)
    {
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
        {
            count+=1;
            total+=count;

        }
        else
        {
            count = 0;
        }
    }

    return total;
}


int main()
{

    vector<int>nums = {1,2,3,4};
    cout<<numberOfArithmeticSlices(nums)<<endl;

    return 0;

}