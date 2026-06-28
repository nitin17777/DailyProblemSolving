#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    //Two guilds are considered different if a house that is in one guild and not in other 
    // he wants to know how many different non empty guilds are there in tree

    // a[i] = parent of ith house 

    set<int>st;
    for(auto&x:a)st.insert(x);

    int ans = 2*n - st.size();

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

        for(auto&x:a)cin>>x;

        cout<<solve(a,n)<<'\n';
    }

    return 0;
}