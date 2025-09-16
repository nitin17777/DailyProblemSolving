#include<iostream>
#include<string>
using namespace std;

bool isSym(int num)
{
    string str = to_string(num);// int to length conversion

    int len = num.length();
    if(len %2 != 0)
    return false;

    int half  = len/2;
    int sum1 = 0, sum2 =0;

    for(int i = 0;i< half;i++)
    {
        sum1 += str[i] - '0';

    }
    for(int j = half; j<len; j++)
    {
        sum2 += str[j] - '0';

    }

    return sum1 == sum2;
}

int countSym(int low,int high)
{
    int count = 0;

    // an integer x consisting of 2n digits is symmetric if sum of last and first 'n' digits is same
   
    for(int i = low; i<=high; i++)
    {
        if(isSym(i))
        {
        count++;
        }
    }
    return count;
}

int main()
{

    int low =1;
    int high = 100;

    int ans = countSym(low,high);

    cout<<"Symmetric Elements: "<< ans <<endl;
    
    return 0;

}