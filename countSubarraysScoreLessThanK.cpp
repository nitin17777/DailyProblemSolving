#include<iostream>
#include<vector>
using namespace std;

long long countSub(vector<int>nums, long long k)
{

    //score of any subarray is defined as product of it's sum and length of the subarray : (sum of subarray) * (lenght of subarray) < k


    //we have to find the number of subarrays whose score is less than 'k'

    long long ans = 0; //for storing final count of valid subarrays
    long long sum = 0; // for storing sum of current window
    int left = 0; // left pointer for sliding window


    //iterating over array using 'right' as the end of the window
    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right]; // including current element into sum

        //this while loop checks if the score of the current subarray is too large
        
        //while the score of the subbaray is >= k, shrink the window from left
        while(sum * (right - left + 1) >= k)
        {
            sum -= nums[left]; //removes the element at left bounday from the sum 
            left++; // moves the left pointer rightwards to shrink the window
        }
        ans += (right - left + 1); // all subarrays ending at right are valid
    }
    return ans;
}


int main()
{
    vector<int>nums = {2,1,4,3,5};
    long long k = 10;

    long long ans = countSub(nums,k);

    cout<<ans<<endl;

    return 0;

}