#include<iostream>
using namespace std;

bool isPower(int n)
{
    //we have to find if n is power of 4 or not
    return (n>0) &&((n & (n-1))==0) && ((n & 0x55555555) != 0);
}

int main()
{

    int n = 5;

    if(isPower(n))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;

}