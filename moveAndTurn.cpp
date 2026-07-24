#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll n;
    cin>>n;

    //How many different positions can robot reach at the end
    

    //the direction alternates actually 

    if (n % 2 == 0) 
    {
        // n = 2k
        ll k = n / 2;
        cout << (k + 1) * (k + 1) << '\n';
    }
    else
    {
        // n = 2k + 1
        ll k = n / 2;
        cout << 2LL * (k + 1) * (k + 2) << '\n';
    }
    return 0;
}