#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,vector<int>&b,int n)
{
    //Number of steps to convert a into b 

    int ans = 0;
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

        vector<int>a(n),b(n+1);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;

        cout<<solve(a,b,n)<<endl;    
    }

    return 0;
}
