#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Didn't much understood this question much fr

bool solve(ll n)
{
    //A number is lage if all of it's digit are large

    //Determine if x can be the sum of two large positive numbers with same number of digits and being a LARGE number itself

    /*We are checking if the number fits the given certain pattern by us

    1 [digits from 1 to 9] [last digit from 0 to 8]

    So first digit = 1, no zero can be in the middle and last digit <=8


    */
    ll last = n%10;

    last = (last+1)%10;

    n = n/10 * 10 + last;


    //Checkingg all the digits except the first

    while(n>=10)
    {
        if(n%10 ==0)return false;

        n/=10;
    }

    //first digit must be 1
    if(n==1)return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;

        cout<<(solve(n)?"Yes":"No")<<endl;
        
    }
    return 0;
}