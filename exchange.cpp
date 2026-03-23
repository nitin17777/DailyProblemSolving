#include<bits/stdc++.h>
using namespace std;

int solve(int n,int a,int b)
{
    /*

    n = weapon cost
    a = 
    b = 

    Sell 1 gold for 'a' silver coins
    Buy 1 gold for 'b' silver coins

    Calculate number of quests that he has to complete to have atleast n silver coins 

    */

    ///In this case , he can go infinite by obtaining just one gold coin 
   if(a>b)return 1;

    return ((n+a-1)/a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;

        cout<<solve(n,a,b)<<endl;
    }
    return 0;
}