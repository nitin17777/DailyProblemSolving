#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkDivisibility(int n)
{
    int digSum = 0,digProd = 1;

    int t = n;

    while(t)
    {
        int dig = t%10;
        t/=10;

        digProd*=dig;
        digSum+=dig;
    }
    return n%(digSum+digProd) == 0;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(checkDivisibility(99)?"True":"False")<<endl;

    return 0;
}