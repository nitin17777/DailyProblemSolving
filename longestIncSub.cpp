#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findNumberOfLIS(vector<int>& nums)
{
    int n = nums.size();

    //len[i] = length of longest sub ending at i
    //cnt[i] = number of LIS ending at i

    vector<int>len(n,1),cnt(n,1);


    int maxi = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(nums[j] < nums[i])
            {
                if(len[j]+1 > len[i])
                {
                    len[i] = len[j]+1;
                    cnt[i] = cnt[j];
                }

                else if(len[j]+1 == len[i])
                {
                    cnt[i]+=cnt[j];
                }

            }
        }
        maxi = max(maxi,len[i]);
    }

    int ans = 0;

    for(int i = 0;i<n;i++)
    {
        if(len[i] == maxi)ans+=cnt[i];
    }
    return ans;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,3,5,4,7};
    cout<<findNumberOfLIS(a)<<'\n';

    return 0;
}