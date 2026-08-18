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
        ll p,q;
        cin>>p>>q;

        //Alice plays first
    /*

    A player can : p-1 or q-1

    Game ends : p == 0 and q == 1

    Bob wins : p/q == 2/3 anytime during the game,else alice wins 

    3p = 2q ->Game over
    

    Determine the winner
    */

    //Condition 1:q>p,else bob wont have any chance to match our given expression
    //condition 2 : 
        //If alice decreases p, then bob decreases q to keep q-p constant 


        if((q>p) && min(p/2, q/3) >= q-p)cout<<"Bob"<<'\n';
        else cout<<"Alice"<<'\n'; 
    }

    return 0;
}




