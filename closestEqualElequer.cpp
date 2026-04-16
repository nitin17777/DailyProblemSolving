#include<bits/stdc++.h>
#define ll long long
using namespace std;


int findMin(vector<int>&a,int q,int n)
{

    auto it = lower_bound(a.begin(),a.end(),q);
    int idx = it - a.begin();

    int mini = INT_MAX;

    if(idx > 0)
    {
        int dist = abs(q-a[idx-1]);
        mini = min(mini,min(dist,n-dist));
    }

    if(idx<a.size()-1)
    {
        int dist = abs(q-a[idx+1]);
        mini = min(mini,min(dist,n-dist));
    }

    int distFirst = abs(q-a[0]),distLast = abs(q-a.back());

    if(a[0] != q)
    {
        mini = min(mini,min(distFirst,n-distFirst));
    }

    if(a.back() != q)
    {
        mini = min(mini,min(distLast,n-distLast));
    }
    return mini;

    // int mini = INT_MAX;

    // for(int i = 0;i<a.size();i++)
    // {
    //     if(a[i] != q)
    //     {
    //         int dist = abs(q - a[i]);
    //         mini = min(mini, min(dist, n - dist));
    //     }
    // }

    // if (mini == INT_MAX) return -1;
    // return mini;
}


vector<int> solveQueries(vector<int>& nums, vector<int>& queries)
{
    int n = nums.size();

    /*

    For each qurery i , we have to : 

    Find the min distance  : min(nums[queries[i]]  and j such that nums[j] == nums[queries[i]])

    Return ans[i] = answer of query i

    */

    //For every number in nums -> find all the 

    vector<int>ans;

    unordered_map<int,vector<int>>mp;

    //Making map such that we have every index where that number is present
    for(int i = 0;i<n;i++)
    {
        mp[nums[i]].push_back(i);
    }

    //Now going through every query
    for(int q:queries)
    {
        vector<int>&map = mp[nums[q]];

        if(map.size() == 1)ans.push_back(-1);

        else ans.push_back(findMin(map,q,n));
    }
    return ans;   
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,3,1,4,1,3,2},q = {0,3,5};

    vector<int>ans = solveQueries(a,q);

    for(auto &x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}




