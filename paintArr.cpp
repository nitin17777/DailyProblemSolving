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
        int n;
        cin>>n;

        vector<ll>a(n);
        for(auto & x:a)cin>>x;

        /*
        Choose any integer d
        And x%d == 0 -> painted red else paint blue

        Beautiful coloring if no pairs of adjacent elements are of same color

        find that d which yields a beautiful coloring
        
        */

        ll gcd1=0,gcd2=0;

        for(int i = 0;i<n;i+=2)
        {
            gcd1 = __gcd(gcd1,a[i]);
        }

        for(int i = 1;i<n;i+=2)
        {
            gcd2 = __gcd(gcd2,a[i]);
        }

        bool works1 = true;
        //Trying gcd1 first
        for(int i=1;i<n;i+=2)
        {
            if(a[i] %gcd1 == 0)
            {
                works1 = false;
                break;
            }
        }
    
        
        bool works2 = true;
        if(gcd2 == 0)works2 = false;


        else
        { 
            //Trying gcd2 now
            for(int i=0;i<n;i+=2)
            {
                if(a[i] %gcd2 == 0)
                {
                    works2 = false;
                    break;
                }
            }
        }

        if(works1)
        {
            cout<<gcd1<<'\n';
        }

        else if(works2)
        {
            cout<<gcd2<<'\n';
        }
        else cout<<0<<'\n';
    
    }

    return 0;
}