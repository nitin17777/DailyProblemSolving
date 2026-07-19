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
        int n,k,m;
        cin>>n>>k>>m;

        //sum is divisble by m and length of that array = k
        if(k>m)
        {
            cout<<"No"<<'\n';
            continue;
        }

        cout<<"Yes"<<'\n';

        for(int i = 0;i<n;i++)
        {
            cout<<(i%k == 0? m-k+1 : 1)<<" ";
        }
        cout<<"\n";   
    }
    return 0;
}