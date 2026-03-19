#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//To check good numbers
bool good(ll x)
{
    return (x%2 != 0 && x%3 != 0 && x%5 != 0 && x%7 != 0);
}


//To count good numbers in [0,x-1]
ll getnaive(ll x)
{
    ll cnt = 0;

    for(int i = 0;i<x;i++)
    {
        if(good(i))cnt++;
    }
    return cnt;
}



ll get(ll r)
{
    //Integer is good if all primes in it's prime factorisation are of atleast 2 digits

    //Return the number of good integers from l to r

    //Also we canb say that: A number is good i fit is not divisible by 210 : gcd(x,210)

    const int L = 210;

    return (r/L) * getnaive(L) + getnaive(r%L);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<get(r+1) - get(l)<<endl;
    }
    return 0;
}