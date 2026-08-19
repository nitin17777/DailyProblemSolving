#include<bits/stdc++.h>
#define ll long long
using namespace std;

int majorityElement(vector<int>& nums)
{
    int n = nums.size();
    unordered_map<int,int>freq;
    for(auto&x:nums)freq[x]++;

    for(auto&x:freq)
    {
        if(x.second > n/2)return x.first;
    }
    return -1;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {3,2,3};
    cout<<majorityElement(nums)<<endl;

    return 0;
}