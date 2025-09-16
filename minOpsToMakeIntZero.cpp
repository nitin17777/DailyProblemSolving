#include<iostream>
#include<cmath>
using namespace std;

int countBits(long long x)
{
    int cnt = 0;
    while(x>0)
    {
        cnt+=(x&1);
        x>>=1;
    }
    return cnt;
}

int makeTheIntegerZero(int num1, int num2)
{
    //We can subtract 2^i + num2 from nums1 in one operation
    for(int k = 1; k<=60;k++)
    {
        long long target = long long(num1) - (long long)k *num2;

        if(target<0)break;

        int bits = countBits(target);

        if(bits<=k && k<= target)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    cout<<makeTheIntegerZero(3,-2)<<endl;

    return 0;
}



