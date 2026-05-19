#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(vector<int>&a,int n,int X)
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
        int n,x;
        cin>>n>>X;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,n,X)<<endl;


    
    }

    return 0;
}