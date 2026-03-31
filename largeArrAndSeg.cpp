#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,int n,int k,int x)
{
    //An array b is created from array a
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;

        vector<int>a(n);
        foR(auto&x:a)cin>>x;

        cout<<solve(a,n,k,x)<<endl;
        
    }
    return 0;
}