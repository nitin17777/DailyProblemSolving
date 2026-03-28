#include<bits/stdc++.h>
using namespace std;


//Checking if card x beats y
bool beats(int n, int x,int y)
{

    //Since first card beats the last card
    if(x == 0)return y == n-1;

    if(x == n-1)return y !=0;

    return x>y;
}

string solve(string &s)
{
    int n = s.size();

    //Card with number i beats j if i > j except: Card 1 beats card n



    /*

    During each turn: 
    Alice chooses one of his cards and places it face up on the table


    Player with no card at their turn loses the game

    Determine the winner of the game
    */


    //We just need to check who will be the winnner fo 1st round, becsue then all the remaining cards of opponent would surely be smaller

    //So check if alice has any card that beats bob
    bool aliceWins=false;

    for(int i = 0;i<n;i++)
    {

        //Skipping if this card doesn't belong to alice
        if(s[i] !='A')continue;

        bool goodMove = true;

        for(int j = 0;j<n;j++)
        {

            //If bob's card beats alice's card
            if(s[j] == 'B' && beats(n,j,i))
            {
                goodMove = false;
                break;
            }
        }

        if(goodMove)
        {
            aliceWins = true;
            break;
        }
    }

    if(aliceWins)return "Alice";

    else return "Bob";
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
        string s;
        cin>>s;

        cout<<solve(s)<<endl;
        
    }
    return 0;
}