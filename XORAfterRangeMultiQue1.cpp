#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();

    /*

    queries[i] = li, ri, ki, li

    idx = li
    while idx <= ri: 
                    nums[idx] = (nums[idx] * vi) % MOD
                    idx+=ki    
    */

    for(int a:queries)
    {
        int idx = a[0];

        while(idx <= a[1])
        {
            nums[idx] = (1LL*nums[idx] * a[3])%MOD;
            idx+=a[2];
        }
    }

    int ans = 0;
    for(auto&x:nums)
    {
        ans^=x;
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,1,1};

    vector<vector<int>>q = {{0,2,1,4}};
    cout<<xorAfterQueries(a,q)<<endl;

    return 0;
}