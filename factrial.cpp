#include<iostream>
using namespace std;


int factorial(int n )
{
    if(n == 0 || n == 1)
    {
        return 1;

    }

    return n * factorial(n-1);

}

int main()
{
int num;
    cout<<"Enter the number."<<endl;

    cin>>num;

    int g = factorial(num);

    cout<<"Factorial is "<<g<<endl;

    return 0;

}