#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        a[0] = 1;

        for(int i = 1; i < n; i++)
        {
            a[i] = 1LL * i * (i+1);
        }

         for(auto x : a)
            cout << x << " ";

        cout << endl;
    }
}