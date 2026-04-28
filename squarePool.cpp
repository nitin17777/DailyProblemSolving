#include<bits/stdc++.h>
#define ll long long
using namespace std;

int countNumbersWithUniqueDigits(int n)
{
    //Return the count of all numbers with unique digits

    if(n == 0)return 1;

    int ans = 10;
    int unique = 9;
    int avail = 9;


    for(int i = 2; i<=n;i++)
    {
        unique = unique * avail;
        ans+=unique;
        avail--;
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<countNumbersWithUniqueDigits(2)<<endl;


    return 0;
}