#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPowerOfFour(int n)
{
    if (n <= 0) return false;

    while (n % 4 == 0)n /= 4;

    return n == 1;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(isPowerOfFour(16)?"true":"false")<<endl;

    return 0;
}