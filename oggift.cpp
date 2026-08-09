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
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto&x:a)cin>>x;


        //find the max score we can obtain 
        sort(a.begin(),a.end());

        int diff = a[n-1]-a[0];

        cout<<diff*(n-1)<<'\n';
    }

    return 0;
}




