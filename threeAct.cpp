#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int>getbest3(vector<int>&a)
{
    int mx1 = -1,mx2= -1,mx3 = -1;

    for(int i = 0;i<(int)a.size();i++)
    {
        if(mx1== -1 || a[i] > a[mx1])
        {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        }
        else if(mx2 ==-1 || a[i] > a[mx2])
        {
            mx3 = mx2;
            mx2 = i;
        }

        else if(mx3 == -1 || a[i] > a[mx3])
        {
            mx3 = i;
        }
    }

    return {mx1,mx2,mx3};
}

      
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

        vector<int> a(n), b(n), c(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];


        vector<int> A = getbest3(a);
        vector<int> B = getbest3(b);
        vector<int> C = getbest3(c);

        ll ans = 0;

        for(auto &x:A)
        {
            for(auto & y:B)
            {
                for(auto & z:C)
                {
                    if(x!=-1 && y!=-1 && z!=-1 && x!=y && x!=z && y!=z)
                    {
                        ans = max(ans,1LL*a[x] + b[y] + c[z]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}