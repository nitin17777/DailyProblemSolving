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
        int m,a,b,c;
        cin>>m>>a>>b>>c;

        //2 rows with m seats each

        //Max number of monkeys ball can seat

       int ans = 0,rem=0;

       ans+=min(m,a);
       rem+=m-min(m,a);
       
       ans+=min(m,b);
       rem+=m-min(m,b);

       ans+=min(rem,c);
       
       cout<<ans<<'\n';
    }
    return 0;
}