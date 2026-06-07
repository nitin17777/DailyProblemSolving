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

        vector<int>a(n);
        for(auto &x:a)cin>>x;

        
        sort(a.rbegin(),a.rend());

        if(n==2)
        {
            cout<<a[0]<<" "<<a[1]<<endl;
            continue;
        }

        bool ok = true;
        for(int i=0;i<=n-3;i++)
        {
            if(a[i+2] != a[i] % a[i+1])
            {
                ok = false;
                break;
            }
        }

        if(!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << a[0] << " " << a[1] << endl;
        }
    }

    return 0;
}