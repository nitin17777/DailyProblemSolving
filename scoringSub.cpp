#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int>solve(vector<int>&a,int n)
{

    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int l = 1,r= i+1;


        while(l<=r)
        {
            int m = (l+r)/2;
            if(a[i-m+1]>=m)l=m+1;

            else r = m-1;
        }

        res.push_back(r);
    }
    return res;
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
        for(auto& x:a)cin>>x;

        //Score = 

        //m = max score of a subsequence
        
        for(auto& x:solve(a,n))cout<<x<<" ";

        cout<<'\n';
    
    }

    return 0;
}