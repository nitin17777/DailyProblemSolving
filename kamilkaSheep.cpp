#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>&a)
{
    int n= a.size();

    //Find the max possible pleasure she can have

    //gcd(a,b) = gcd(a,b-a)

    sort(a.begin(),a.end());
    return a[n-1] - a[0];
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
        cout<<solve(a)<<endl;

        
    }
    return 0;
}