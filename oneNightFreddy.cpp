#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a,int m,int l)
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,l;
        cin>>n>>m>>l;
        vector<int>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,m,l)<<endl;
    
    }
    return 0;
}