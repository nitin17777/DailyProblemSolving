#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{

    int ans = 0;
    for(auto & x:a)
    {
        ans |= x;
    }
    return ans;
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int>a(n);

        for(auto &x:a)cin>>x;

        cout<<solve(a)<<endl;
        
    }
}