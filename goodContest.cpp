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

        int a,b,c;
        cin>>a>>b>>c;

        cout<<n-min({a,b,c})<<'\n';
    }

    return 0;
}