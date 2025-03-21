#include<iostream>
#include<vector>
using namespace std;

int maxAscendingSum(vector<int>& nums) 
{

    int sum = 0;
    int maxSum = 0;

    int i = 0;

        if(nums.empty())
    {
        return 0;

    }

            while(i < nums.size() - 1)
        {
            if(nums[i-1]>nums[i])
            {
                sum +=nums[i];

                maxSum = max(maxSum,nums[i]);
                sum = 0;
            }

            if(nums[i-1] < nums[i])
            {
                sum+=nums[i];

            }
            i++;
        }
        sum+=nums[i];
        maxSum = max(maxSum,sum);
        return maxSum;
}


int main()

{
    vector<int>arr = {6,10,6};

    int ans = maxAscendingSum(arr);

    cout<<ans<<endl;

    return 0;

}
