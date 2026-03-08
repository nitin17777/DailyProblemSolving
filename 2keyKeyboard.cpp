#include<bits/stdc++.h>
using namespace std;

int minSteps(int n)
{
    //Return the min number of ops to get char 'A' exactly n times on the screeen
   
    int ans =0;

    //Min ops = sum of prime factors of n

    for(int i = 2;i<=n;i++)
    {
        while(n%i == 0)
        {
            ans+=i;
            n/=i;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minSteps(10)<<endl;
    
    return 0;
}