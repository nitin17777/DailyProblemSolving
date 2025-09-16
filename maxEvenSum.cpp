#include<bits/stdc++.h>
using namespace std; 
#define ll long long

ll solve(int a, int b)
{
    //choose an integer k such that b is divisible by k
    ll maxEvenSum = -1;
    for(int k = 1; k<=b ;k++)
    {
        //then multiply a by k and divide b by k
        if(b%k == 0)
        { 
            ll newA = a*k;
            ll newB = b/k;

            ll sum = newA + newB;

            //if now sum of a+b is even
            if(sum % 2 == 0)
            {
                maxEvenSum = max(sum, maxEvenSum);
            }
        }
    }
    return maxEvenSum;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        ll ans = solve(a,b);

        cout<<ans<<endl;
    }
    return 0;
}