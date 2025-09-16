#include<iostream>
#include<vector>
using namespace std;

vector<int>merge(const vector<int>&left, const vector<int>&right)
{
    vector<int>result;
    int i=0,j=0;

    while(i < left.size() && j <right.size())
    {
        if(left[i] <= right[j])
        {
            result.push_back(left[i++]);
        }
        else
        {
            result.push_back(right[j++]);
        }
    }
//we will reach here only if one of the numsay is completely exhausted
    while(i<left.size())
    {
        result.push_back(left[i++]);
    }

     while(j<right.size())
    {
        result.push_back(right[j++]);
    }
    return result;
}

    vector<int> sortArray(vector<int>& nums) {

        int left = 0;
        int right = nums.size()-1;

        if(nums.size() <= 1) //base case
        return nums;
        
        int mid = nums.size()/2;

        vector<int>leftt(nums.begin(), nums.begin()+mid);
        vector<int>rightt(nums.begin()+mid, nums.end());

        vector<int>leftPart = sortArray(leftt);
        vector<int>rightPart = sortArray(rightt);

        return merge(leftPart,rightPart);
    }


    int main()
    {
        vector<int>arr = {12,11,13,5,6,7};
    
        vector<int>ans =sortArray(arr);
    
        cout<<"Sorted Array : ";
        for(auto num : ans)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    
        return 0;
    
    }