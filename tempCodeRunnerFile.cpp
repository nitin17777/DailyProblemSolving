#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n,int x,int y)
{
    /*
    P1 + P2 => Winner + P3 => winner + P4...and so on, total of n-1 games are played and at last the winner of last game wins the game 


    Each player has either won x games or y games in championship


    Find the winner


    therefore possible iff: 

    min(x,y) = 0
    max(x,y)>1
    (n-1)%max(x,y) = 0;
    */


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;


        if(x>y)swap(x,y);


        if(x!= 0 || y == 0 || (n-1) %y != 0)
        {
            cout<<-1<<"\n";
            continue;
        }

        int printed = 0;
        for(int winner = 0;printed<n-1;winner+=y)
        {
            for(int cnt = 0; cnt< y &&printed < n-1;cnt++)
            {
                cout<<winner<<' ';
                printed++;
            }

            cout<<"\n";
        }    
    }

    return 0;
    
}