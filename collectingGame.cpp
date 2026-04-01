#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int>solve(vector<int>&a)
{

    int n = a.size();

    /*

    IF score >= ai -> increase score by ai and remove ai from array 

    For each i ,determine the max number of array elements we can remove if we remove ai 
    */

    vector<pair<int,int>>arr;
    for(int i = 0;i<n;i++)arr.push_back({a[i],i});

    sort(arr.begin(),arr.end());
    //Put the number which we are checking at the front of the array and then start counting the ans

    vector<ll>prefix(n);
    prefix[0] = arr[0].first;
    for(int i =1;i<n;i++)
    {
        prefix[i] = prefix[i-1] + arr[i].first;
    }

    vector<int>nxt(n);//To check the farthest index we can reach starting from i
    nxt[n-1] = n-1;

    for(int i = n-2;i>=0;i--)
    {
        if(prefix[i] >= arr[i+1].first)
        {
            nxt[i] = nxt[i+1];
        }
        else nxt[i] = i;
    }

    //Building answer now

    vector<int>ans(n);

    for(int i = 0;i<n;i++)
    {
        int originalIdx = arr[i].second;
        ans[originalIdx] = nxt[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto &x:a)cin>>x;

        vector<int>ans = solve(a);
        for(auto &x:ans)cout<<x<<" ";

        cout<<endl;

        
    }
    return 0;
}