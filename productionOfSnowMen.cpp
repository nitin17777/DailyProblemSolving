#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool good(vector<int>&a,vector<int>&b,int n, int k)
{
    for(int i = 0;i<n;i++)
    {
        if(a[i]<= b[(i+k)%n])return false;
    }
    return true;
}

      
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

        vector<int>a(n),b(n),c(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;
        for(auto &x:c)cin>>x;

        ll k1 = 0,k2 = 0;

        //We need to determine the number of suitable combos of parameters
        for(int i = 0;i<n;i++)
        {
            if(good(b,a,n,i))k1++;
            
            if(good(c,b,n,i))k2++;
        }

        cout<<k1*k2*n<<'\n';

    }
    return 0;
}