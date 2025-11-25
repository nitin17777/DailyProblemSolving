#include <bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k)
{
    int rem = 1;
    int len = 1;

    while (rem % k != 0)
    {
        int num = rem * 10 + 1;
        rem = num % k;
        len += 1;
    }

    return len;
}

/*
int smallestRepunitDivByK(int k)
{
    /*Fidn the length of the smallest positive integer n such that n is divisible by k and n only contains digit 1


    Return the length, if there is no such n return -1



    if(k%2 == 0 || k % 5 ==0)return -1;//number with only '1' as digit can never be divisible by any even number

    int num = 1;

    bool done = false;

    while(!done)
    {
        string str = to_string(num);

        if(num%k==0)
        {
            done = true;
            return str.size();
        }

        else
        {
            str = str + '1';
            num = stoi(str);
        }
    }
    return -1;

}
*/

int main()
{
    cout << smallestRepunitDivByK(3) << endl;

    return 0;
}
