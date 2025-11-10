#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    vector<int> s;

    int res = 0;

    for (int a : nums)
    {
        while (!s.empty() && s.back() > a)
        {
            s.pop_back();
        }

        if (a == 0)
            continue; // no need to do anything when current element is 0

        if (s.empty() || s.back() < a)
        {
            res++;
            s.push_back(a);
        }
    }
    return res;
}

// int minOperations(vector<int>& nums)
// {
//     int ops = nums[0];

//     for(int i = 0; i<nums.size();i++)
//     {
//         if(nums[i] > 0 && (i ==0) || nums[i-1] == 0)
//         {
//             ops++;
//         }
//     }
//     return ops;
// }

/*
int solve(vector<int>&nums,int l , int r)
{
    if(l>r)return 0;//base case

    // for(int  i = 0;i<=r;i++)mn = min(mn , nums[i]);
    int mn = INT_MAX;
        for (int i = l; i <= r; i++) {
            mn = min(mn, nums[i]);
        }

    if (mn == 0) {
            int i = l, ops = 0;
            while (i <= r) {
                while (i <= r && nums[i] == 0) i++;
                int j = i;
                while (j <= r && nums[j] != 0) j++;
                if (i <= r) ops += solve(nums, i, j - 1);
                i = j;
            }
            return ops;
        }


    //Subtracting every occurence of mn from our array
    for(int i = l;i<=r;i++)
    {
        nums[i]-=mn;
    }

    int ops = 1;//Counted our first operation

    int i = l;

    //Recursively solving for each non zero sub segment
    while(i<=r)
    {
        while(i<=r && nums[i] == 0)i++;// skip in case of '0'

        int j = i;
        while(j<=r && nums[j] != 0)j++;


        if(i <=r)ops += solve(nums,i,j-1);//Recurse on this subsegement

        i = j;//now moving to next subsegment
    }
    return min(r-l+1,ops);
}

int minOperations(vector<int>& nums)
{
    //select any subarray and set all occurences of minimum number to 0

    //return minOps required

    //Algo: Select subarray consisting of max occcurences that element
    return solve(nums,0,nums.size()-1);
}*/

int main()
{
    vector<int> nums = {1, 2, 1, 2, 1, 2};
    cout << minOperations(nums) << endl;

    return 0;
}
