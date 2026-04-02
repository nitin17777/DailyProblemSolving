#include<bits/stdc++.h>
using namespace std;

int integerBreak(int n)
{

    //Break the given n into sum of k integers  and maximise the product of those integers

    // Return the max product we can get


    //By observation : Any number >= 5 is always better when broken : 7 = 4*3 =12(greater than 5)

    if(n == 2)return 1;
    if(n == 3)return 2;

    int product = 1;
    
    //SO in any number, we will be maximising the use of '3' as it is closest to the optimal piece size ~ 2.718(IMPORTANT RESULT)
    
    while(n>4)
    {
        product *= 3;
        n-=3;
    }
    return product * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<integerBreak(2)<<endl;

    return 0;
}