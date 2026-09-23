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

        vector<int>last(1001);

        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            last[a] = i;        
        }

        /*
        max i+j such that ai and aj are coprime

        Coprime = whenn their gcd = 1 
        */

        

        int ans = -1;
        for(int x = 1;x<=1000;x++)
        {
            for(int y = 1;y<=1000;y++)
            {
                if(last[x] && last[y] && __gcd(x,y)==1)
                {
                    ans=max(ans,last[x]+last[y]);
                }
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}