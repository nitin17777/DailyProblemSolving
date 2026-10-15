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
        int n,m;
        cin>>n>>m;

        //Number of colors that suit him
        //Only knows: 1,2, any number greater than 2

        //Brain Melts -> When no valid coloring 

        //So even if one node is isolated -> Brain melts
        

        //atleast one neighbour of different color is needed

        //Answer can never be 1 as per given constraints

        //so we just need to determine bw 2 and many


        //answer will be 2 when given graph is a star 


                   /*  Like this 

                   C
                   |
                   A--B
                   |
                   D


                   */

        vector<int>d(n);

        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;

            x--;
            y--;

            d[x]++;
            d[y]++;
        }

        sort(d.begin(),d.end());

        //If any isolated node -> No possible way
        if(d[0] == 0)cout<<"Brain Melt"<<'\n';

        //If max degree is n-1 and remaining degrees = 1 - >answer would be 2
        else if(d[n-1] == n-1 && d[n-2] == 1)cout<<2<<'\n';

        //Else answer would always be greater than 2
        else cout<<"Many"<<'\n';

        // 1 as answer is never possible
    
    }

    return 0;
}