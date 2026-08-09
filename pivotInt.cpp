#include<bits/stdc++.h>
#define ll long long
using namespace std;

int pivotInteger(int n)
{

    ll sum = 1LL * n*(n+1)/2;
    ll x = sqrt(sum);

    if(x*x == sum)return x;

    return -1;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<pivotInteger(8)<<endl;

    return 0;
}