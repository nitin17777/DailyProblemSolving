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
        int x,y;
        cin>>x>>y;

        cout<<(x%y==0?"Yes":"No")<<'\n';
    
    }

    return 0;
}