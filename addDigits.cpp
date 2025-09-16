#include<iostream>
using namespace std;

/*
int addDigits(int num)
{
    //brute force approach using loop

    while(num >= 10)
    {
        int sum = 0;

        while(num > 0)
        {
            sum += num %10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}
    */

int addDigitss(int num) //digital root concept used(IMPORTANT)
{
    if(num == 0)
    return 0;

    
        if(num %9 == 0)
        return 9;

        else
        return num%9;
}

int main()
{
    int num = 38;

    int ans = addDigitss(num);

    cout<<ans<<endl;

    return 0;

}