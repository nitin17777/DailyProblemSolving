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

        char c;
        cin>>c;

        string s;
        cin>>s;

        //Make all chars in string equal to c using minimum number of operations

        //Op: Choose x<=n and for every position i where i is not divisible by x: replace si with c

        //Find min number of operations to be used and the  xs that should be used
        
        bool allEq = true;

        for(char ch:s)
        {
            if(ch!=c)
            {
                allEq=false;
                break;
            }
        }

        if(allEq)
        {
            cout<<0<<'\n';
            continue;
        }

        bool found = false;

        for(int x=1;x<=n;x++)
        {
            bool ok = true;

            //All multiples of x must already be c
            for(int j = x;j<=n;j+=x)
            {
                if(s[j-1] != c)
                {
                    ok=false;
                    break;
                }
            }

            if(ok)
            {
                cout<<1<<'\n';
                cout<<x<<'\n';
                found = true;
                break;
            }
        }


        if(!found)
        {
            cout<<2<<'\n';
            cout<<n<<" "<<n-1<<'\n';
        }
    }

    return 0;
}