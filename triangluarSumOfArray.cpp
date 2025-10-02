#include <bits/stdc++.h>
using namespace std;

// Optimised approach  :(
int triangularSum(vector<int> &nums)
{
    int n = nums.size();

    long long ans = 0, coeff = 1;

    for (int i = 0; i < n; i++)
    {
        ans += coeff * nums[i];

        coeff = coeff * (n - 1 - i) / (i + 1);
    }
    return ans % 10;
}

/*  BRUTE FORCE: O(n^2)
int triangularSum(vector<int>& nums)
{


    //Triangular sum is the value of only element present in nums aftert the following process terminates

    int n = nums.size();

    //if n == 1 : End the process simply, otherwise create new 0 indexed array newNums of length n-1




    // newNums[i] = (nums[i] + nums[i+1])%10

    //now replace nums with newNums


    //return the triangluar sum finally




    while(n > 1)
    {
        vector<int>newNums(n-1);

        for(int i = 0 ; i < n-1;i++)
        {
            newNums[i] = (nums[i] + nums[i+1])%10;
        }

        nums =newNums;
        n = nums.size();
    }
    return nums[0];
}
    */

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};

    cout << triangularSum(nums) << endl;

    return 0;
}