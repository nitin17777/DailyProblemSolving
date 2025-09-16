#include<bits/stdc++.h>
using namespace std;


/*

// time complexity -> O(n)
int firstMissing(vector<int>&nums)
{
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i] , nums[nums[i] = 1]);

        } 

    }

    for(int i = 0 ; i<n; i++)
    {
        if(nums[i] != i+1)
        {
            return i+1;

        }
    }
    return n+1;  //if no such element found

}
    */






// time complexity : O(nlogn)

int firstMissing(vector<int>nums)
{
    //sort the array
    
    //starting from the first element add 1 and check if the number is present or not if not present it is our answer

    int n = nums.size();
    int missing = 1;


    sort(nums.begin(),nums.end());
    
    
    for(int i =0; i<n; i++)
    {
        if(nums[i] == missing)
        {
            missing++;

        }
    }

    return missing;
    
}*/

int main()
{

    vector<int>arr = {100000, 3, 4000, 2, 15, 1, 99999};

    int ans = firstMissing(arr);

    cout<< ans <<endl;


    return 0;

}

