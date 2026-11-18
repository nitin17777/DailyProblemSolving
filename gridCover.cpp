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
        ll n,m,a,b;
        cin>>n>>m>>a>>b;

        //Wonders if jumping in this manner can cover all tiles of his room

        //n rows and m columns

        //He can either jump b steps right or jump a steps down
        //His moves must alternate 

        //Determine if he can visit all tiles in A in finite number of jumps

        //Each position can be: (i,j,lastDown) or (i,j,lasRight)


        //Path loops entirely after 2*lcm(n,m)
        if((gcd(n,a)==1) && (gcd(m,b) == 1) && (gcd(n,m) <= 2))cout<<"Yes"<<'\n';
        else cout<<"NO"<<'\n'; 
    }

    return 0;
}