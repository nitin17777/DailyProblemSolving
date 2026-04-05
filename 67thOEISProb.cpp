#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        a[0] = 1;

        for(int i = 0; i < n; i++)
        {
            ll bi = 2*i + 1;
            ll bnext = 2* (i+1) + 1;

            a[i] = bi * bnext;
        }

         for(auto x : a)
            cout << x << " ";

        cout << endl;
    }
}