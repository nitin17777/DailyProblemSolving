#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();
    int ans = 0;

    int prev = a[0];
    sort(a.begin(),a.end());
    for(int i =1;i<n;i++)
    {
        int ad = (prev + a[i])/2;
        prev = ad;
    }
    return prev;
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
        for(auto &x:a)cin>>x;

        cout<<solve(a)<<endl;
    }
    return 0;
}