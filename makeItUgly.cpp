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
        

        //Find min block of continuous nunms
        int ans = INT_MAX;

        int left=0;

        if(a[0]!=a[n-1])
        {
            cout<<0<<'\n';
            continue;
        }
      
        //Counting the smallest block of nums[0] in the given array
       
        int target = a[0];
        int cnt = 0;

        for(int x:a)
        {
            if(x==target)cnt++;

            else
            {
                if(cnt>0)ans=min(ans,cnt);
                cnt=0;
            }
        }
        if(cnt>0)ans=min(ans,cnt);
        
        if(ans==n)cout<<-1<<'\n';

        else cout<<ans<<'\n';
        
    }
    return 0;
}