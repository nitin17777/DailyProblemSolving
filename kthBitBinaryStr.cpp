#include<bits/stdc++.h>
using namespace std;

char findKthBit(int n, int k)
{
    if(k==1  || n==1)return '0';

    //We will be going with recursive approach to find the bit

    int len = (1<<n)-1;
    int mid = (len/2)+1;

    if(k == mid)return '1';

    if(k<mid)return findKthBit(n-1,k);

    if(k>mid)
    {
        char ch =  findKthBit(n-1,len-k+1);

        //Inverting the result
        return (ch == '0')? '1':'0';
    }
    return '0';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<findKthBit(3,1)<<endl;

    return 0;
}