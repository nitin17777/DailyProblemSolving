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

        /*
        Operation :

        Find max length of good subsequence 

        */

       int mn = INT_MAX;
        for (int i = 0; i < n; i++) 
        {
            int x;
            cin >> x;
            mn = min(mn, x);
        }
        cout << (mn <= n - 1 ? n : 0) << "\n";
    }

    return 0;
}