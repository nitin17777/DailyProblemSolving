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

        ll L = 0,R = 1000000001LL;
        for(int i = 1;i<=n;i++)
        {
            ll x;
            cin>>x;

            if(i&1)R = min(R,x);
            else L = max(L,x);
        }
        cout << (n % 2 == 0 && L + 2 <= R ? "YES" : "NO") << '\n';
    }

    return 0;
}