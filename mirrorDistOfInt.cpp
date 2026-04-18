#include<bits/stdc++.h>
#define ll long long
using namespace std;

int reverseint(int n)
{
    ll ans = 0;

    while(n)
    {
        int rem = n%10;
        n/=10;

        ans = ans*10 + rem;

        // check overflow
        if(ans > INT_MAX || ans < INT_MIN)return 0;       
    }
    return (int)ans;
}

int mirrorDistance(int n)
{
    /*

    Mirror distance = abs(n-reverse(n))

    reverse and return the abs diff
    */

    return abs(n-reverseint(n));
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<< mirrorDistance(25)<<endl;

    return 0;
}
