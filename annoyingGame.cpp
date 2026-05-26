#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,vector<int>&b,int n,int k)
{
    /*
    final score = max non empty subarray sum of modified array a


    
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
        int n,k;
        cin>>n>>k;

        vector<int>a(n),b(n);

        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;

        cout<<solve(a,b,n,k)<<endl;
    }

    return 0;
}




