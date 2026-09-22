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
        int a,b,c;
        cin>>a>>b>>c;

        //Alice starts first

        //if 

        if(a>=b)cout<<a-b+c<<'\n';
        else if(a<b)cout<<max(b-a,a+c-b)<<'\n';
    
    }

    return 0;
}