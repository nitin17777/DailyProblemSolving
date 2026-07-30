#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minimumPushes(string word)
{
    /*

    1-8 : 1 click
    8-16 : 2 click
    16-24 : 3 click
    25,26 -> 4 click

    len = 10 = 8+2 = 1*8 + 2*2

    n = 20 

    div = 2   -> 2*8 + 8 = 24
    rem = 4   -> 3*8 = 24
    
    */



    int n = word.size();

    int ans = 0;

    int div = n/8;
    int rem = n%8;

    int k = div;

    while(k)
    {
        ans+=(k*8);
        k--;
    }

    ans+=(rem*(div+1));

    return ans;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minimumPushes("xycdefghij")<<endl;

    return 0;
}





