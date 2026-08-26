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
    
        vector<int>a(n),b(n);

        //Amount of each sort of tea
        for(auto&x:a)cin>>x;
        
        //Amount of tea each tater can drink
        for(auto&x:b)cin>>x;
        
        //First step -> ith taster tastes ith sort of tea and drinks min(ai,bi) tea and ai decreases by this amount

        //For each taster, determine the amount of tea they will drink in total
        
        vector<ll>pref(n+1,0);
        for(int i = 0;i<n;i++)
        {
            pref[i+1] = pref[i]+b[i];
        }

        //cnt[i] will tells how many times taster i drink b[i] exactly

        //cnt arry will be used as difference array 
        vector<ll>cnt(n+1,0);

        //add[i] stores the amount of remaining tea that taster i receives
        vector<ll>add(n,0);


        for(int i=0;i<n;i++)
        {
            ll target = pref[i]+a[i];
            int j = upper_bound(pref.begin(),pref.end(),target) - pref.begin()-1;

            cnt[i]++;
            cnt[j]--;

            if(j<n)
            {
                ll rem = a[i]- (pref[j]-pref[i]);
                add[j]+=rem;
            }
        }

        for(int i =1;i<n;i++)
        {
            cnt[i] += cnt[i-1];
        }

        for(int i=0;i<n;i++)
        {
            ll ans = cnt[i]*b[i] + add[i];

            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
