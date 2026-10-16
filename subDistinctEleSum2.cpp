#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

struct Node
{
    ll sum=0; //Sum of disticnt counts
    ll sqSum = 0; // sum of squared disticnt counts
    ll lazy = 0; //Pending range increment
};

vector<Node>seg;
int n;

void apply(int node,int l ,int r,ll val)
{
    ll len = r-l+1;

    seg[node].sqSum = 
}





int sumCounts(vector<int>& nums)
{

    nums.size();
    seg.assign(4*n+5,Node());

    vector<int>last(100001,-1);

    ll ans = 0;

    for(int i = 0;i<n;i++)
    {
        int prev = last[nums[i]];


        //icnrement distinct counts for subarrays  startign from prev+1 through i
        update(1,0,n-1,prev+1,i);

        ans = (ans+seg[1])
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    vector<int>nums = {1,2,1};
    cout<<sumCounts(nums)<<'\n';

    return 0;
}