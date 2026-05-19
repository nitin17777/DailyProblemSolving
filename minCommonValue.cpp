#include<bits/stdc++.h>
#define ll long long
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2)
{
    int n=nums2.size();

    set<int>st(nums1.begin(),nums1.end());

    int mini = INT_MAX;

    for(int i = 0;i<n;i++)
    {
        if(st.find(nums2[i]) != st.end())
        {
            mini = min(mini,nums2[i]);
        }
    }

    if(mini == INT_MAX)return -1;

    return mini;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums1 = {1,2,3},nums2 = {2,4};
    cout<<getCommon(nums1,nums2)<<endl;


    return 0;
}