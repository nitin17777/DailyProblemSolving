#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>&a)
{

    //He can choose any two elements and swap them and he can do this only once

    //Find permutation q from p such that number of ugly indices in q is mininmised
    
    //index i is ugly iff i = max(arr)
    sort(a.rbegin(),a.rend());
    return a;
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
        for(int i = 0;i<n;i++)cin>>a[i];

        vector<int>ans = solve(a);
        for(auto&x:ans)cout<<x<<" ";
        
        cout<<endl;
    }
    return 0;
}