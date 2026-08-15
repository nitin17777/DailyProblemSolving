#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        vector<int>a(3);
        for(auto&x:a)cin>>x;

        //choose one integer and replace them with sum of other 2
        //Find the min range we can go upto

        sort(a.begin(),a.end());

        int sum = min(a[2],a[0]+a[1]);
        cout<<sum-a[0]<<'\n';
    }

    return 0;
}