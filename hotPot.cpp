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
        int n,k;
        cin>>n>>k;

        string s;
        cin>>s;

        /*odd numbers -> Red
        even numbers -> Blue

        Game lasts for k rounds


        They either keep the potato or pass it next clockwise,such that next one doesn't hold anything before the round

        Everyone holds atmost 1 potato at once


        After k rounds are over, everyone holding potato will be eliminated
        Score += members of other team which got eliminated


        find the score of both teams finally


        if si = 1 -> he is holding the potato
        */

                    // APPROACH 

        //Play for k rounds , each round follow the rules, update the score and update the string , atlast return both scores

        //We can hold the potato till the last round for 
        int red=0,blue = 0;

        int N = 2*n;

        //Score of blue+red = total potatos in the cycle always

        // In each run, only the last 1 can actually move

        //We will be waiting till the final specaial round and won't move anything before that
        for(int i = 0;i<N;i++)
        {
            int next = (i+1)%N;

            if(s[i] == '1' && s[next] == '0')
            {
                //here i's potato moves away, thus team owning i scores
                if(i%2 == 0)red++;
                else blue++;
            }

            else if(s[i] == '1' && s[next] == '1')
            {
                //In this case opposite team scores
                if(i%2 == 0)blue++;
                else red++;
            }
        }
        cout<<red<<" "<<blue<<" "<<'\n';
    }
    return 0;
}