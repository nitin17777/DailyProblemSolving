#include<bits/stdc++.h>
#define ll long long
using namespace std;

int int_ceil(int x,int d)
{
    return (x+d-1)/d;
}
      
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

        int ans = int_ceil(n,x+y);//ceil division

        //IF usese ai -> maxim uses ai for first z hours ,so lines = x*z and remaining = n - x*z lines and after this speed = x+10y

        //so z + max(0,n-xz / x+10y)  ceil

        if(z*x<=n)
        {
            ans = min(ans,int_ceil(n-z*x, x+10*y)+z);
        }
        cout<<ans<<'\n';   
    }

    return 0;
}