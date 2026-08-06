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
    
        string s;
        cin>>s;

        cout << (s.front() != s.back() ? "YES" : "NO") << '\n';

    }

    return 0;
}