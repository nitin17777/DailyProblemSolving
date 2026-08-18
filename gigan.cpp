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
        int n,m;
        cin>>n>>m;

        //Beas range : a(left to right), ver's b(right to left)

        //in each turn height of each other 's tower is decreased by 1

        //As soon one is standing on 0 height he has to accept the defeat

        //bea goes first

        //Determine who will win

        ll a0,b0;
        cin>>a0;

        ll skip;
        for(int i = 1;i<n;i++)cin>>skip;

        cin>>b0;
        for(int i = 1;i<m;i++)cin>>skip;

        ll bea = a0+n;
        ll ver = b0+m;

        cout<<((bea>=ver)?1:2)<<'\n';
    }
    return 0;
}