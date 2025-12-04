#include<bits/stdc++.h>
using namespace std;

vector<int>order(vector<int>&h,int k)
{

    /*

    Decrease k from the greatest element everytime, if several greates elements are there, on with smaller index will be decresed,

    Keep pushing elements in ans array as soon as they become less than equal to 0

    
    //Determine the order in which they will move

    //

    ALGO:

    push element with min mod first, if many start with smaller index
    
    //store (index,mod) pair

    sort with mod value and if mod same , consider the smaller index first
    */

    int n = h.size();
    vector<pair<int,int>>p; //index,mod

    for(int i=0;i < n;i++)
    {
        int mod = h[i] % k;
        p.push_back({i+1, mod});
    }
    sort(p.begin(),p.end(), [&](auto & a,auto&b)
    {
        if(a.second == b.second)return a.first < b.first;

        return a.second < b.second;

    });

    vector<int>ans; 
    for(auto & pr :p)
    {
        ans.push_back(pr.first);
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
        int n,k;
        cin>>n>>k;

        vector<int>h(n);
        for(auto&x:h)cin>>x;

        vector<int>ans = order(h,k);
        for(auto&an : ans)cout<<an<<" ";

        cout<<endl;
    }

    return 0;
    
}