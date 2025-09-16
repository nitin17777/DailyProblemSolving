#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>getMaxSubsequence(vector<int>&nums,int k)
{
    
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    int m = nums1.length();
    int n = nums2.length();

    //nums1 and nums2 represents the digits of two numbers 

    //we have to create a max numebr of length k <= m+n; form digits of these two numbers with relative order of digits preserved

    //return array of k digits representing answer

    //so we have to select the big numbers from both arrays but the order of digits of both arrays should be same


    vector<int>best;

    for(int i)






}
        

int main()
{

    vector<int>nums1 = {3,4,6,5};
    vector<int>nums2 = {9,1,2,5,8,3};

    int k = 5;

    vector<int>ans = maxNumber(nums1,nums2,k);

    cout<<ans<<endl;

    return 0;
    
}
