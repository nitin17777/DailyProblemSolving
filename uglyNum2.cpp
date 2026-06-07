#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isUgly(int n)
{
    
    if(n<=0)return false;

    while(n%2 == 0)n/=2;
    while(n%3 == 0)n/=3;
    while(n%5 == 0 ) n/=5;

    return n==1;
}

int nthUglyNumber1(int n)
{

    //Ugly number is such that it's prime factors are only limited to 2,3 and 5
    int k = 1;
    int cnt = 0;

    while(true)
    {
        if(isUgly(k))
        {
            cnt++;

            if(cnt == n)return k;
        }
        k++;
    }
    return 0;
}

int nthUglyNumber(int n)
{
    vector<ll>ugly(n);

    ugly[0] = 1;
    int i2 =0,i3 = 0,i5 = 0;


    for(int i = 1;i<n;i++)
    {
        ll next2 = ugly[i2] *2;
        ll next3 = ugly[i3] *3;
        ll next5 = ugly[i5] *5;


        ll nextUgly = min({next2,next3,next5});

        ugly[i] = nextUgly;  

        if(nextUgly == next2) i2++;
        if(nextUgly == next3) i3++;
        if(nextUgly == next5) i5++;
    } 
    return ugly[n-1];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<nthUglyNumber(10)<<endl;

    return 0;
}