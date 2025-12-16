#include<bits/stdc++.h>
using namespace std;

bool can(int n,int m, int p, int q)
{
    if(n%p == 0 && (n/p)*q != m)return false;

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
        int n,m,p,q;
        cin>>n>>m>>p>>q;

        cout<<(can(n,m,p,q)? "Yes" : "No")<<endl;
    }
    return 0;
    
}