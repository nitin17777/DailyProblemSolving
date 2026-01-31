#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{

    int n = a.size();

    unordered_map<int,int>freq;
    for(auto&c:a)freq[c]++;


    int maxi = 0;
    for(auto&c: freq)
    {
        maxi = max(maxi,c.second);
    }

    return n-maxi;
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

        cout<<solve(a)<<endl;
    }
    return 0;
}