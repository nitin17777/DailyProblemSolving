#include<bits/stdc++.h>
using namespace std;


vector<int>solve(vector<int>&p)
{
    int n = p.size();

    /*
    ith song has predicted rating p1 p2


    
    */
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

        vector<int>ans = solve(p);
        for(auto& x:ans)cout<<x<<" ";

        cout<endl;
        
    }
    return 0;
}