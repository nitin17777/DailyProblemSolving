#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int s)
{
    int n = a.size();

    //In one step, we can move either forward or backeward by 1 step

    int maxi = a[n-1],mini = a[0];

    int ans = min(abs(s-maxi),abs(s-mini))+ maxi-mini;

    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,s;
        cin>>n>>s;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,s)<<endl;
    
    }

    return 0;
}