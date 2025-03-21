#include<iostream>
using namespace std;

int fib(int n)
{
    //base case
    if(n==0 )
    return 0;
    
    if(n == 1)
    {
        return 1;
    }


    //recursive call
int ans = fib(n-1) + fib(n-2);

return ans;

}
int main()
{

    int num = 3;

    int gg = fib(num);

    cout<<gg<<endl;

    return 0;

}