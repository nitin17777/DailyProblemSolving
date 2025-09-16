#include<bits/stdc++.h>
using namespace std;


int minIndex(vector<int>&nums)
{
    int n = nums.size();
 //An element will be dominant if freq of any element > arraySize/2;
 

    // we have to return the index of breaking such that both the broken arrays have same dominant element


    // firstly we can count the frequency of every element 
    //then we can check 

    //storing the frequency of every element
    int dominant = -1,total_count = 0;

    
    unordered_map<int,int>freq;
    for(int i = 0;i<nums.size();i++)
    {
        freq[nums[i]]++;
    }

    for(auto &entry : freq)
    {
        if(entry.second *2 > n)
        {
            dominant = entry.first;
            total_count = entry.second;
            break;
        }
    }

    int prefix_count = 0;
    for(int i = 0; i<n-1; i++)
    {
        if(nums[i] == dominant)
        {
            prefix_count++;
        }
    

      if(prefix_count * 2 > (i+1) && (total_count - prefix_count) * 2 > (n-i-1))
        {
            return i;
        }
    }

}

int main()
{
    vector<int>arr = {2,1,3,1,1,1,7,1,2,1}; 

    int ans = minIndex(arr);

    cout<<ans<<endl;

    return 0;

}