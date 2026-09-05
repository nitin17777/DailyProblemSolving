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

        //n friends will be arranged in queue
    
        //There are m pairs that don't know each other. and pairs not in this list are already friends        

        //Good when all the pairs of subsegments of queue are friends

        //How many pairs are such that subsegment starting from a and ending at b is good

        //everyone knows themselves , so ans starts with n

        //Naive approach -> Find the number of pairs and subtract m form it 

        //mn[i] = max possible position where segment starting at i can end, 
        vector<int>mn(n+2,n);

        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;

            if(x>y)swap(x,y);

            //Cannot include y
            mn[x] = min(mn[x],y-1);
        }

        //Propagating restrictions to left
        for(int i = n-1;i>=1;i--)
        {
            mn[i] = min(mn[i],mn[i+1]);
        }

        ll ans=0;

        //counting possible ending positions
        for(int i=0;i<n;i++)ans+=(mn[i]-i);

        cout<<ans<<'\n';
    }
    return 0;
}