#include<iostream>
using namespace std;

int diff(int n, int m)
{
    // num1 = sum of all integers in range 1,n that are not divisble by m
    int num1 = 0;
    for(int i = 1; i<n; i++)
    {
        if(i%m != 0)
        {
            i += num1;
        }

        else
        continue;
    }
    
    //num2 = sum of all integers in range 1,n that are divisible by m
    int num2 = 0;
    for(int i =0;i <n; i++)
    {
        if(i%m ==0)
        {
            i += num2;

        }
        else continue;
    }
}


int main()
{
    int n = 10;
    int m = 3;

    int ans = diff(n,m);

    cout<<ans<<endl;
    return 0;

}