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
        int n,q;
        cin>>n>>q;

        vector<int>a(n);

        for(auto & x:a)cin>>x;
        

        int minPr = 31;

        while(q--)
        {
            int x;
            cin>>x;

            if(x>=minPr)continue;

            minPr = x;

            ll powerx =(1LL << x);
            ll addVal = (1LL << (x-1));

            for(int i = 0;i<n;i++)
            {
                if(a[i] %powerx == 0)
                {
                    a[i] += addVal;
                }
            }
        }
        for(auto & x:a)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}