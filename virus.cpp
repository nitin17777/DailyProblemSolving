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

        vector<int>a(m);
        for(auto&x:a)cin>>x;

        sort(a.begin(),a.end());
        /*

        m houses are initially affected by virus 

        Protects an uninfected house permanently and each day atleast one neighbour becomes infected 

        Min number of houses that will be infected at last

        //We need to start by securing the boundarires first
        
        
        */

        vector<ll>gaps;


        //Segments that are uninfected bw consecutive infected house
        for(int i =1;i<m;i++)
        {
            gaps.push_back(a[i]-a[i-1]-1);
        }

        //circular 
        gaps.push_back((n-a.back()) + a.front()-1);

        //Sorting based on largest gap
        sort(gaps.rbegin(),gaps.rend());


        ll days = 0;//Days already spent on saving
        ll saved = 0; //Houses saved till now
    

        for(ll len : gaps)
        {
            ll rem  = len - 2*days;

            //Segment already infected
            if(rem<=0)continue;

            if(rem == 1)
            {
                saved+=1;
                days+=1;
            }

            else 
            {
                saved +=rem -1;
                days+=2;
            }        
        }
        cout<<n-saved<<'\n'; 
    }
    return 0;
}