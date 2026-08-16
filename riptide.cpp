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
        vector<int> v(3);
        for(int &x : v) cin >> x;
        sort(v.begin(), v.end());
        cout << min(v[2] - v[1], v[1] - v[0]) << endl;
    
    }

    return 0;
}