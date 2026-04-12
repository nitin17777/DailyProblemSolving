#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(ll p,ll q)
{

    //Alice plays first
    /*

    A player can : p-1 or q-1

    Game ends : p == 0 and q == 1

    Bob wins : p/q == 2/3 anytime during the game

    Determine the winner

    
    */

    if(p>q) return "Alice";
    ll a = min((p/2), (q/3));
    ll b = q-p;

    if(a >=b)return "Bob";

    return "Alice";
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll p,q;
        cin>>p>>q;

        cout<<solve(p,q)<<endl;
    }

    return 0;
}




