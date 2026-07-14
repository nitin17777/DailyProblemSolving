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
        for(auto& x:a)cin>>x;

        //Neat if array is increasing strictly

        //Just make every element equal to their index first, and then check for strict increasing

        
        ll rem = 0;
        if(a[0] > 1)rem = a[0]-1;
        a[0] = 1;

        bool ok = true;
        for(int i = 1;i<n;i++)
        {
            ll need = (a[i-1]+1)-a[i];

            rem-=need;

            if(rem < 0)
            {
                ok = false;
                break;
            }
            a[i]= a[i-1]+1;
        }

       
        for(int i = 1;i<n;i++)
        {
            if(a[i]<=a[i-1])
            {
                ok = false;
                break;
            }
        }

        cout<<(ok?"Yes":"No")<<'\n';
    }

    return 0;
}