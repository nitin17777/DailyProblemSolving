#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isGood(int num)
{
    bool changed = false;

    while(num > 0)
    {
        int digit = num%10;

        if(digit == 3 || digit == 4 || digit == 7)return false;

        if(digit == 2 || digit == 5 || digit == 6 || digit == 9)changed = true;

        num/=10;
    }
    return changed;
}


int rotatedDigits(int n)
{

    //Number is valid if digit remains digit even after rotation
    //Determine how many valid number are there from 1 to n inclusive

    int cnt = 0;

    for(int i = 1;i<=n;i++)
    {
        if(isGood(i))cnt++;
    }
    return cnt;
}




      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<rotatedDigits(10)<<endl;
    
    return 0;
}




