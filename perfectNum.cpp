#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkPerfectNumber(int n)
{

    //number that is equal to sum of it's positive divisors

    if(n<=1)return false;

    int sum = 1;

    for(int i = 2;i*i <= n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i!=n/i)sum+=n/i;
        }
    }
    return sum == n; 
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<checkPerfectNumber(28)<<endl;


    return 0;
}