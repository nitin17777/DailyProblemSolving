#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,vector<int>&b,int k )
{

    int n = a.size();

    //Return the number of possible arrays b such that a and b are complemnetary

    int s = -1;
    
    for(int i=0;i<n;i++)
    {
        if(b[i] != -1)
        {
            if(s == -1)s= a[i] + b[i];

            else
            {
                if(s != a[i] + b[i])return 0;
            }
        }
    }

    if(s == -1)
    {
        sort(a.begin(),a.end());
        int mx = a[n-1] - a[0];
        return k-mx+1;
    }

    for(int i =0 ;i<n;i++)
    {
        if(a[i]>s || s - a[i] > k)return 0;
    }
    return 1;
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
        for(auto& x:b)cin>>x;

        cout<<solve(a,b,k)<<endl;
    }
    return 0;
}