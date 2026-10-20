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
        int n;
        cin>>n;

        int evens=0,odds=0;

        vector<int>a(n);
        for(auto&x:a)
        {
            cin>>x;

            if(x&1)odds++;
            else evens++;
        }

        //Mogity starts first and then alternates

        //Remove some elements from array if: We remove exactly one element is remove OR sum of removed elements is even

        //Finally the player who faces an emepty array in his turn looses the game
        
        // Determine the winning player


        //This is the only case where larpity can win
        if(((odds == 3) && (evens ==0)) || (evens == 1 && odds == 1))
        {
            cout<<"Larpity"<<'\n';
            continue;
        }

        cout<<"Moggity"<<'\n';

        // //If even number of odds are there -> Moggity wins directly
        // if(odds%2==0)
        // {
        //     cout<<"Moggity"<<'\n';
        //     continue;
        // }

        // else
        // {
        //     if(evens==0)
        //     {
        //         cout<<"Larpity"<<'\n';
        //         continue;
        //     }
        // }
        // cout<<"Moggity"<<'\n';
    }
    return 0;
}