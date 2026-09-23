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
        int n,s;
        cin>>n>>s;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        int total = accumulate(a.begin(),a.end(),0);

        int target = total-s;

        if(target<0)
        {
            cout<<-1<<'\n';
            continue;
        }

        if(target==0)
        {
            cout<<0<<'\n';
            continue;
        }

        int left = 0;
        int ans = 0;
        int maxLen = -1;
    
    }

    return 0;
}