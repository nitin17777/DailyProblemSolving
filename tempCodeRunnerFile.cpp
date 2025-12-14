#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    //next greater element of x is the first greater element which is to the right of x in the same array

    //For each i in nums1 , find j such that nums[i] == nums[j] and determine the next greater element of nums2  , if no greater element is there , return -1

    int n = nums1.size(), m = nums2.size();

    //we can precompute next greater element in right for every element

    unordered_map<int,int>nge;
    stack<int>st;

    for(int x : nums2)
    {
        while(!st.empty() && x> st.top())
        {
            nge[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }

    //Now the remaining elements don't have any next greater, so put - for them

    while(!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    vector<int>ans;
    for(int x: nums1)
    {
        ans.push_back(nge[x]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<int>nums1 = {4,1,2},nums2 = {1,3,4,2};

   vector<int>ans = nextGreaterElement(nums1,nums2);
   for(auto & an: ans)cout<<an<<" ";

   cout<<endl;

    return 0;
    
}