#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,vector<int>&b,int n,int c)
{
    int totalDiff1 = 0;
    for(int i=0; i<n; i++)
    {
        int diff = a[i]-b[i];

        if(diff<0)
        {
            totalDiff1 = INT_MAX;
            break;
        }
        totalDiff1+=diff;
    }

    //Now we have rearranged -> 
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    int totalDiff2 = c;

    for(int i = 0;i<n;i++)
    {
        int diff = a[i]-b[i];
        if(diff<0)return -1;

        totalDiff2+=diff;
    }

    return min(totalDiff1,totalDiff2);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,c;
        cin>>n>>c;

        vector<int>a(n),b(n);

        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;

        //We need to convert array a into b

        cout<<solve(a,b,n,c)<<'\n';
    }
    return 0;
}