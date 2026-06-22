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

        for(auto& x:a)cin>>x;

        sort(a.rbegin(), a.rend());
        
        bool ok = true;

for (int i = 0; i < n - 1; i++)
{
    if (a[i] == a[i + 1])
    {
        ok = false;
        break;
    }
}

if (!ok)
{
    cout << "-1\n";
    continue;      // goes to next test case
}

for (auto x : a)
    cout << x << " ";

cout << "\n";
    }

    return 0;
}