#include<bits/stdc++.h>
using namespace std;

int reverseBits(int n)
{
    unsigned int res = 0;

    for(int i = 0;i<32;i++)
    {
        res <<= 1;
        res |= (n &1);

        n>>=1;
    }
    return res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<reverseBits(43261596)<<endl;

    return 0;
}