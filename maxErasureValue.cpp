#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int maximumUniqueSubarray(vector<int>& nums)
{
    unordered_map<int,int>freq;

    int maxSum = 0,sum = 0;

    int left =0;

    for(int right = 0; right<nums.size(); right++)
    {
        sum+=nums[right];
        freq[nums[right]]++;


        while(freq[nums[right]] >1)
        {
            freq[nums[left]]--;
            sum -= nums[left]; 
            left++;

        }

        maxSum = max(sum ,maxSum);
    }

    return maxSum;
}


/*
int maximumUniqueSubarray(vector<int>& nums)
{

    unordered_map<int,int>freq;
    //we want to erase a subarray containing unique elements
    //score obtained = sum of elements

    //we have to return the maximum score we can get by erasing exactly one subarray

    //each element in removed subarray must be unique

    int maxSum = 0;
    int sum = 0;
    for(int i = 0;i < nums.size(); i++)
    {
        
        if(freq[nums[i]]==0) //if the number has already came in our counted array
        {
            sum+=nums[i];
            maxSum = max(sum,maxSum);
            freq[nums[i]]++;
        }

        else if(freq[nums[i]] >=1)
        {
           freq.clear(); //but if the number is already present, reset the frequency 
           freq[nums[i]]++;
           sum=nums[i]; //make this number as new sum
           maxSum = max(sum,maxSum);
        }      
    }

    return maxSum;
}
*/
int main()
{

    vector<int>nums = {4,2,4,5,6};

    int ans = maximumUniqueSubarray(nums);

    cout<<ans<<endl;
    return 0;
    
}
