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
        ll n,m;
        cin>>n>>m;

        // n = old price of the good
        // m = number of times we can increase the price n


        /*

        We are allowed to increase the price of goods by k times  : 1<= k <= m
        
        Return the roundest possible price of good -> One with max number of zeros at the end

        If there are several variants -> Return the one with maximal price
        If not possible to get a rounder price -> return n*m

        
        */

        //Final answer would be n*k

        //cnt and cnt5 -> Denotes the degree of occurence of 2 and 5 in number n

        ll n0 = n;
        ll k = 1;

        int cnt2=0,cnt5=0;


        while(n>0 && n%5==0)
        {
            n/=5;
            cnt5++;
        }

        while(n>0 && n%2==0)
        {
            n/=2;
            cnt2++;
        }

        //Making max number of pairs to get max number of zeros
        while(cnt2<cnt5 && k*2<=m)
        {
            cnt2++;
            k*=2;
        }

        while(cnt5<cnt2 && k*5<=m)
        {
            cnt5++;
            k*=5;
        }


        //Now directly increasing number of zeros after both 2 and 5 are equal
        while(k*10 <= m)
        {
            k*=10;
        }

        if(k==1)cout<<n0*m<<'\n';
        
        else
        {
            k*=m/k;
            cout<<n0*k<<'\n';
        }
    }

    return 0;
}