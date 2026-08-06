#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool check(int n,int t)
{
    int k = n;

    int pr = 1;

    while(k)
    {
        int rem = k%10;
        k/=10;

        pr*=rem;
    }
    return pr%t==0;
}

int smallestNumber(int n, int t)
{
    for(int i = n;i<=n+10;i++)
    {
        if(check(i,t))return i;
    }
    return 0;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cout<<smallestNumber(15,3)<<endl;
    
    return 0;
}