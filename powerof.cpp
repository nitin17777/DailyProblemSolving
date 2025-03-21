#include<iostream>
using namespace std;


int powerOf(int num ,int power)
{
    if( power == 0)
    {
        return 1;

    }
    if(power == 1)
    {
        return num;
    }
    int ans = powerOf(num,power/2);

    if(power % 2 == 0)
    {
        return ans*ans;

    }
    else
    {
        return num* ans * ans;

    }
}


int main()
{

    int a,b;

    cin>>a>>b;

    int ans = powerOf(a,b);

    cout<<"Answer is : "<<ans<<endl;

    return 0;

}