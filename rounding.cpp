#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;


    ll div = n/10;

    ll n1 = div*10;
    ll n2 = n1+10;

    ll diff1 = abs(n-n1);
    ll diff2 = abs(n-n2);

    cout<<(diff2<diff1 ? n2 : n1)<<endl;
    return 0;
}