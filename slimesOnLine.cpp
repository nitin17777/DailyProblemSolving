#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{

    sort(a.begin(),a.end());

    return ((a[n-1]-a[0]+1)/2);   
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

        cout<<solve(a,n)<<endl;
    
    }

    return 0;
}