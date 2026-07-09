#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries)
{

    //Construct full graph, and add required edges

    vector<bool>ans;
    //For each query i, determine if there exists an edge bw ui and vi

    vector<int>comp(n);


    int id = 0;

    for(int i = 1;i<n;i++)
    {
        if(nums[i]-nums[i-1]>maxDiff)id++;

        comp[i] = id;
    }

    for(auto&q:queries)
    {
        ans.push_back(comp[q[0]] == comp[q[1]]);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int>nums = {1,3};

    vector<vector<int>>q = {{0,0},{0,1}};
    vector<bool>ans = pathExistenceQueries(2,nums,1,q);

    for(auto x:ans)cout<<x<<" ";

    cout<<endl;
    
    return 0;
}