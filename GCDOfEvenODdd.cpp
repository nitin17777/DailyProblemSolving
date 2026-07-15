#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcdOfOddEvenSums(int n)
{

    //gcd(sumOdd,sumEven)

    int sumEven=0,sumOdd = 0;
    int i = 1,j=2;

    int t = n;
    while(t--)
    {
        sumOdd+=i;
        sumEven+=j;

        i+=2;
        j+=2;
    }
    return __gcd(sumOdd,sumEven);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<gcdOfOddEvenSums(4)<<endl;
    return 0;
}