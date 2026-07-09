#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e9+7;
      
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

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        //left 

        vector<ll>pref1(n+1),pref2(n+1);
        for(int i =0;i<n;i++)
        {
            pref1[i+1] = pref1[i] + (a[i]==1?1:-1); 
            pref2[i+1] = pref2[i] + (a[i]==3?-1:1);
        }

        ll mn = INF;
        bool ok = false;

        for(int i = 1;i<n;i++)
        {
            //if in that range after first cut, prefix sum is positive, then YES
            if(pref2[i]-mn >= 0)
            {
                ok = true;
                break;
            }

            //We can make the first cut here 
            if(pref1[i]>=0)
            {
                mn = min(mn,pref2[i]);
            }
        }
        cout<<(ok?"Yes\n":"No\n");
    }

    return 0;
}