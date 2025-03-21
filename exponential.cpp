#include<iostream>
using namespace std;


double factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n-1);

}

double power(int x , int n )
{
    if(n == 0)
    {
        return 1;
    }

    return x * power(x, n-1);
}


double exp(int x ,int n)
{
    if(n == 0)
    {
        return 1;
    }

        return exp(x,n-1) + (power(x,n)/factorial(n));
}

int main()
{

    int x = 4;

    int n = 19;

    
    int ans = exp(x,n);

    cout<<ans<<endl;

    return 0;

}