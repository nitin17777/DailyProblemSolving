#include<bits/stdc++.h>
using namespace std;

int robotSim(vector<int>& com, vector<vector<int>>& obs)
{
    int n = com.size();
    
    /*

    -2: Turn fully to left 
    -1: Turn fully to right


    1<=k<9 : Move forward k units, one unit at a time
    obstacales[i] = (xi,yi)
    */

    // Return the max squared euclidean distance that robot reahes at any point in it's path

    int maxi = 0;

    set<pair<int,int>>st;
    //storing obstacles
    for(auto & o : obs)
    {
        st.insert({o[0],o[1]});
    }

    //Directions now
    vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int x = 0,y = 0;//Since robot is starting at origin 

    int d = 0;//Starting with face towards north

    int maxDist = 0;

    for(auto & c:com)
    {
        if(c == -1)
        {
            d = (d+1) %4;//right turn
        }
        else if(c == -2)
        {
            d = (d+3) % 4;//left turn
        }

        else
        {
            for(int i = 0;i<c;i++)
            {
                int nx = x + dir[d].first;
                int ny = y + dir[d].second;


                if(st.count({nx,ny}))break;

                x = nx;
                y = ny;

                maxDist = max(maxDist, (x*x + y*y));
            }
        }
    }
    return maxDist;   
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>c = {4,-1,3};
    vector<vector<int>>o = {};

    cout<<robotSim(c,o)<<endl;


    return 0;
}