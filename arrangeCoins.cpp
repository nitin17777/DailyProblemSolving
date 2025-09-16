#include<iostream>
#include<cmath>
using namespace std;

int arrangeCoins(int n)
{
    //ith row has exactly i coins 
    //The last row can be incomplete

    return(int)((sqrt(1LL + 8LL*n) -1)/2);

}


int main()
{
    cout<<arrangeCoins(5)<<endl;
    return 0;

}