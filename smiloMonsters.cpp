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

        vector<ll>a(n);
        for(auto &x:a)cin>>x;

        /*

        ith horde contains ai monsters

        We have to destroy all the monsters

        We have 2 types of attacks : 
        1->choose i from 1 to n -> such that there is atleast one monster i in the horde with number i -> adn then kill one monster from horde i and then combo combo x increases by 1

        2->use ultimate attack and kill x monsters from the horde
        with number i, after that x resets to zero


        Determine min number of attacks required to win the game

        1 2 2 3 4 5

        with second move -> We can remove atleast sum/2 monsters

        
        */


        sort(a.begin(),a.end());

        int i=0,j=n-1;

        ll combo = 0;

        ll ans = 0;
        while(i<j)
        {

            //IF we can't kill the largest horde despite destroying the current smallest horde
            if(combo + a[i] < a[j])
            {
                combo+=a[i];
                ans+=a[i];
                i++;
            }
            
            else
            {
                //need only enough normal attacks to make combo equal to a[j]
                ll need = a[j]-combo;

                ans+=need;
                a[i]-=need;
                combo+=need;

                // ultimate on largest horde
                ans++;
                a[j]-=combo;
                
                //Reset the combo now
                combo = 0;

                //Move forward if empty
                if(a[i]==0)i++;

                //Move backward if empty
                if(a[j]==0)j--;
            }    
        }
        
        //Handling final horde  now
        if(i==j)
        {
            ll m = a[i];
            ll c = combo;

            ll k = max(0LL, (m-c+1)/2);//ceil((m-c)/2)

            ans+=min(m,k+1);
        }
        cout<< ans << '\n';
    }
    return 0;
}