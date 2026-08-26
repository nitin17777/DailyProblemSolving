#include<bits/stdc++.h>
#define ll long long
using namespace std;


int missingMultiple(vector<int>& nums, int k)
{
    int n = nums.size();

    set<int>st(nums.begin(),nums.end());

    for(int i = 1;;i++)
    {
        if(st.find(k*i) ==st.end())return k*i;
    }
    return 0;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {8,2,3,4,6};
    cout<<missingMultiple(nums,2)<<endl;
    return 0;
}