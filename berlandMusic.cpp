#include<bits/stdc++.h>
using namespace std;

//on the watchlist, cux didn't understood the solution much

vector<int>solve(vector<int>&p,string &s)
{
    int n = p.size();

    /*
    ith song has predicted rating p1 p2
    */

    vector<vector<int>>v;
    for(int i =0;i<n;i++)
    {
        v.push_back({s[i],p[i],i});
    }

    sort(v.begin(),v.end());


    vector<int>q(n);
    for(int i =0;i<n;i++)
    {
        int originalIdx = v[i][2];
        q[originalIdx] = i+1;
    }

    return q;

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

        vector<int>p(n);
        for(auto & x:p)cin>>x;

        string s;
        cin>>s;

        vector<int>ans = solve(p,s);
        for(auto& x:ans)cout<<x<<" ";

        cout<<endl;
        
    }
    return 0;
}