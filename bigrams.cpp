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
        vector<ll> a(n);
        for(auto& x:a)cin>>x;

        ll maxi = 0,cnt2=0;
        
        for (auto &x : a)
        {
            maxi = max(maxi, x);
            if (x >= 2) cnt2++;
        }

        if (maxi >= 3 || cnt2 >= 2)cout << "Yes"<<'\n';
        else cout <<"NO"<<'\n';
    
    }

    return 0;
}