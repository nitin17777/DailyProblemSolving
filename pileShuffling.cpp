#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ll final = 0;

        while(n--)
        {
            ll a,b,c,d;
            cin>>a>>b>>c>>d;

            ll ans = 0;

            if(b>d)
            {
                ans += a + b-d;
            }
            else if(a>c)
            {
                ans+= (a-c);
            }

            final += ans;
        }
        cout<<final<<endl;
    }
    return 0;
}