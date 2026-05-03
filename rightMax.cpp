#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>&a,int n)
{
    //Choose the rigthmost max element from array and delete all elements after it including it

    int mx = 0; 
    int ans = 0;

    for(auto &x:a)
    {
        if(x>=mx)ans++;
        mx = max(mx,x);
    }
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
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;

    
    }

    return 0;
}