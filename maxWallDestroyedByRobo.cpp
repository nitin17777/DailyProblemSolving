#include<bits/stdc++.h>
using namespace std;


int maxWalls(vector<int>& r, vector<int>& d, vector<int>& w) 
{
    /*
    Return the max number of unique walls that can be destroyed by the robots


    Every bullet can either fire left or to the right at most d[i]meters
    
    */

    int n = r.size();

    vector<pair<int,int>>robots;
    for(int i = 0;i<n;i++)
    {
        robots.push_back({r[i],d[i]});
    }

    sort(robots.begin(),robots.end());
    sort(w.begin(),w.end());

    unordered_set<int>destroyed;//To track destroyed walls

    for(int i = 0; i < n ;i++)
    {
        int pos = robots[i].first;
        int dist = robots[i].second;

        //Determining blocking robots
        int leftBlock = (i == 0? INT_MIN : robots[i-1].first);
        int rightBlock = (i == n-1? INT_MAX : robots[i+1].first);
        
        //Now computing valid shooting range
        int L = max(pos - dist, leftBlock + 1);
        int R = min(pos + dist, rightBlock - 1);

       //Left side shooting

        if(L <= pos - 1)//Valid interval
        {
            //First wall >= leftL
            auto it = lower_bound(w.begin(),w.end(),L);

            while(it != w.end() && *it <= pos -1)
            {
                destroyed.insert(*it);
                it++;
            }
        }


        //Right side shooting

        if(pos+1 <= R)
        {
            auto it = lower_bound(w.begin(),w.end(),pos+1);

            //iterating all the walls inside rightL and rightR
            while(it != w.end() && *it <= R)
            {
                destroyed.insert(*it);
                it++;
            }
        }
    }
    return destroyed.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>r = {10,2},d = {5,1}, w = {5,2,7};
    cout<<maxWalls(r,d,w)<<endl;

    return 0;
}