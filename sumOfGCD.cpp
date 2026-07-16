#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long gcdSum(vector<int>& nums)
{
    int n=nums.size();
    vector<ll>pgcd(n);
    ll mx = 0LL;

    for(int i = 0;i<n;i++)
    {
        mx = max(mx,nums[i]);
        pgcd[i] = __gcd(nums[i],mx);
    }

    sort(pgcd.begin(),pgcd.end());

    ll ans = 0LL;

    for(int i = 0;i<n/2;i++)
    {
        ans+= __gcd(pgcd[i],pgcd[n-i-1]);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a={2,6,4};

    cout<<gcdSum(a)<<endl;

    return 0;
}