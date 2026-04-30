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

        //Can move two steps forward in any coordinate
        //short step : one step in any coordinate (allowed only once)

        //Determine if he can reach x,y

        if(x%2 != 0 && y%2 != 0)cout<<"NO"<<endl;

        else cout<<"Yes"<<endl;
    }

    return 0;
}