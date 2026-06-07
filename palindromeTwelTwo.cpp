#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPal(ll x)
{
    string s = to_string(x);
    string t = s;
    reverse(t.begin(),t.end());
    return s == t;
}
      

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        bool found = false;

        //200 is just to be on safer side to be greater than 22
        for(ll a = 0; a <= min(n, 200LL); a++)
        {
            if(isPal(a) && (n-a)% 12 == 0)
            {
                cout << a << " " << (n - a) << endl;
                found = true;
                break;
            }
        }

        if(!found)cout << -1 <<endl;
    }

    return 0;
}