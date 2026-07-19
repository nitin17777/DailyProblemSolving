#include<bits/stdc++.h>
#define ll long long
using namespace std;

// vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
// {
//     int n = nums.size();


//     vector<int>gcdPairs;

//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i+1;j<n;j++)
//         {
//             gcdPairs.push_back(__gcd(nums[i],nums[j]));
//         }
//     }

//     sort(gcdPairs.begin(),gcdPairs.end());


//     vector<int>ans;
//     for(auto & x:queries)
//     {
//         ans.push_back(gcdPairs[x]);
//     }
//     return ans;
// }

vector<int> gcdValues(vector<int>& nums, vector<long long>& queries)
{

    int n = nums.size();
    int max = *max_element(nums.begin(),nums.end());

    //
    vector<int>freq(mx+1);
    for(auto& x:nums)freq[x]++;

    //cnt[i] = how many numbers are divisible by i
    vector<int>cnt(mx+1);
    for(int i = 1;i<=mx;i++)
    {
        for(int j = i;j<=mx;j+=i;)
        {

            cnt[i]+=freq[j];
        }
    }


    // gcdCnt[i] = number of pairs whose gcd is exactly 1

    vector<ll>gcdCnt(mx+1);

    for(int i = mx;i>=1;i--)
    {
        ll total = 1LL * cnt[i] * (cnt[i]-1)/2;


        for(int j =2*i;j<=mx;j+=i)
        {
            total-=gcdCnt[j];
        }
    }

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums={2,3,4};
    vector<ll>q={0,2,2};

    vector<int>ans = gcdValues(nums,q);
    for(auto&x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}