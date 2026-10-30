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
        for(auto&x:a)cin>>x;

        //Determine if yaseer is happy or not
        
        //Yaseer has to take all atleast once

        ll sum = 0;
        //IF we somehow get to know about the best possible sum of any segment, we can determine it then easily

        bool ok = true;
        for(int i = 0;i<n;i++)
        {
            sum+=a[i];
            if(sum <= 0)
            {
                ok = false;
                break;
            }
        }

        sum = 0;
        for(int i = n-1;i>=0;i--)
        {
            sum+=a[i];
            if(sum <= 0)
            {
                ok = false;
                break;
            }
        }
        cout<<(ok?"Yes":"No")<<'\n';
    }
    return 0;
}