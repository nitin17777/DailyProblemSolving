#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n)
{

    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

int modString(const string &s, int m)
{
    int r = 0;
    for (char c : s)
    {
        r = (r * 10 + (c - '0')) % m; // No problem in building the digti now cuz n is capped to max  now
    }
    return r;
}

/* This solution is not logically wrong, it's just that it would be not acceptabele for bigger input values

vector<ll> solve(ll n, ll d)
{
    /*
    Digit 'd' exactly n! times

    ll times = fact(n);

    ll num = 0;

    while(times > 0)
    {
        num = num *10 + d;
        times--;
    }

    vector<ll>ans;

    for(ll i = 1;i<=9;i+=2)
    {
        if(num %i == 0)ans.push_back(i);
    }
    return ans;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;

        // vector<ll>ans = solve(n,d);
        // for(auto & an:ans)cout<<an<<" ";

        // Because 7! = 5040 and contains factors : 1,3,5,7,9 => So we can simply cap it
        n = min(n, 7);
        ll cnt = fact(n);

        string num(cnt, '0' + d); // making that required string

        for (int d = 1; d <= 9; d += 2)
        {
            if (modString(num, d) == 0)
            {
                cout << d << " ";
            }
        }
        cout << endl;
    }
    return 0;
}