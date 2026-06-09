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
        int n,x,y,z;
        cin>>n>>x>>y>>z;

        /*

        MAxim -> x

        Nik -> No ai and speed = y
               Or z hours setting ai and then speed  = 10y

        Project completed when x + t = n

        Min number of hours to write code

        
        */

        ll t1= (n+x+y-1)/(x+y);
      
        ll maxi = (n+x-1)/x;

        ll t2;

        if(maxi <=z)t2 = maxi;

        else t2 = z + (n - 1LL*z*x + (x + 10LL*y) - 1) / (x + 10LL*y);

        cout<<min(t1,t2)<<endl;
    }

    return 0;
}