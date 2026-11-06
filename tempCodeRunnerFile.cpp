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
    
        vector<int>a(n);
        for(auto&x:a)cin>>x;

        //In one operation -> coordinate of point changes by b power of 2 exactly
        //Perform n ops of this type : Chooose any point and increase it's coordinate by 1


        //find max doubled area of triangle ABC


        // vector<ll>power(n);
        // for(int i = 0 ;i < n;i++)power[i] = 1>>a[i];

        sort(a.rbegin(), a.rend());   // descending

        ll x = 0, y = 0;
        for(int i = 0; i < n; i++)
        {
            ll v = 1LL << a[i];
            if(x <= y) x += v;
            else y += v;
        }

        cout << x * y << '\n';
    }

    return 0;
}