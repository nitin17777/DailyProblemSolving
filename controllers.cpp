#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int p=0,m=0;

    for(auto&x:s)
    {
        if(x=='+')p++;
        else m++;
    }

    int q;
    cin>>q;

    while(q--)
    {
        ll x,y;
        cin>>x>>y;

        ll tot = p-m;

        if(p==m)
        {
            cout<<"YES"<<'\n';
            continue;
        }

          

        if(y==x)
        {
            cout<<"NO"<<'\n';
            continue;
        }


        ll nume = tot*y;
        ll denom = y-x;

        if(nume%denom !=0)
        {
            cout<<"NO"<<'\n';
            continue;
        }

        ll k = nume/denom;
       
        if(k >= -m && k <= p)cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    //Controller has only 2 buttons and each button has a number written on it
    //Press one of the two buttons on the controller once 

    //After all rounds end -> we will win if score = 0;

    // buttons on jth controller have numbers aj and bj written on them 

    //for each controller determine if we can win the game 
    return 0;
}