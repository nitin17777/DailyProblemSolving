#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x;
        cin>>n;


        vector<int>a(n);
        for(auto& y:a)cin>>y;

        /*

        He can use x to steal coins
        He chooses an index :  ai>0 && gcd(ai,x) != 1 , if no such index -> pirate stops

        He steals gcd(ai,x) = g coins from pile i , after which ai decrease by g
        sets x to g and continue stealing

        Determine max number of coins he can steal       
        
        */
       if(x==1)
       {
            cout<<0<<'\n';
            continue;
       }

       //Coins in pile i can be represented as p*g
       


    
    }

    return 0;
}