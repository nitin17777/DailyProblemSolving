#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n,s,p;
    cin>>k>>n>>s>>p;

    int num = ((n+s-1)/s)*k;

    cout<<(num+p-1)/p<<'\n';

    return 0;
}