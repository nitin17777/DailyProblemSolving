#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    if(n<=0)
    return false;

    while(n%3 == 0)
    {
        n/=3;
    }
    if(n == 1)
    return true;

    else
    return false;
}

/*
bool isPowerOfThree(int n )
{
    int num = 0 ;
    for(int i =0; pow(3,i) <= n;i++)
    {
        num = pow(3,i);
        if(num == n)
        return true;
    }
    return false;
}
*/

int main()
{

    int n = 27;

    if(isPowerOfThree(n))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    //cout<<(isPowerOfThree(n) ? "True" : "False")<<endl;
    return 0;
    
}