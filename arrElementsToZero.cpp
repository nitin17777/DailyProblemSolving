#include <bits/stdc++.h>
using namespace std;

int countValidSelections(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int rightSum = sum;
    int leftSum = 0;

    for (int i = 0; i < n; i++)
    {
        rightSum -= nums[i];

        if (nums[i] == 0)
        {

            if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1)
            {
                ans++;
            }

            if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1)
            {
                ans++;
            }
        }
        leftSum += nums[i];
    }
    return ans;
}

/*
int countValidSelections(vector<int>& nums)
{
    //start by selecting a curr position such that : nums[curr] == 0 + choose a moovement direction left or right

    //if curr is out of range, process ends

    // if(nums[curr] == 0) move in the direction you were moving by incrementing or decrementing

    //if nums[curr] > 0 : Decrement nums[curr] by 1 + reverse movement direction

    //selection of initial posi curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process

    //we have to return the number of such possible selections

    int n = nums.size();

    int count = 0;

    for(int start = 0;start<n;start++)
    {
        if(nums[start] != 0)continue;


        for(int dir : {-1,1})
        {
            vector<int>temp = nums;

            //current position and direction
            int curr = start;
            int d = dir;


            while(curr>=0 && curr < n)
            {
                if(temp[curr] == 0)curr+=d;

                else
                {
                    temp[curr]--;//Decrease that number

                    d=-d;//Reverse the direction

                    curr+=d;//and move one step in new direction
                }
            }

            bool allZero = all_of(temp.begin(),temp.end(),[](int x){return x == 0;});

            if(allZero)count++;
        }
    }
    return count;
}
    */

int main()
{
    vector<int> arr = {16, 13, 10, 0, 0, 0, 10, 6, 7, 8, 7};
    cout << countValidSelections(arr) << endl;

    return 0;
}
