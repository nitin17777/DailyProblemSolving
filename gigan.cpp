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

        vector<int>a(n),b(m);
        for(auto&x:a)cin>>x;

        //Beas range : a(left to right), ver's b(right to left)

        //in each turn height of each other 's tower is decreased by 1

        //As soon one is standing on 0 height he has to accept the defeat

        //bea goes first

        //Determine who will win

        int as,bs = 0;

        for(int i=1;i<n;i++)
        {
            as+= a[i-1]-a[i]+1;
        }
        as+=a[n-1];

        for(int i=1;i<m;i++)
        {
            bs+=b[i-1]-b[i]+1;
        }
        bs+=a[m-1];

        




    
    }

    return 0;
}