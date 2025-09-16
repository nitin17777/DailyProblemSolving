#include<iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    //return true if it is a power of 2, otherwsie return false

    if(n>0 && (n&(n-1)) == 0)
    return true;

    else
    return false;
}


int main()
{

    int n= 5;
    if(isPowerOfTwo(n))
    {
        cout<<"True"<<endl;
    }

    else
    {
        cout<<"False"<<endl;
    }
    return 0;

}