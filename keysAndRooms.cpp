#include<bits/stdc++.h>
using namespace std;


void dfs(int room,vector<vector<int>>& rooms,vector<bool>&vis)
{

    //Mark the room visited
    vis[room] = true;


    for(int key: rooms[room])
    {
        if(!vis[key])
        {
            dfs(key,rooms,vis);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms)
{
    int n = rooms.size();

    //Go to every, collect every key in a set,then check move on opening the rooms
    vector<bool>vis(n,false);

    dfs(0,rooms,vis);

    for(bool v:vis)
    {
        if(!v)return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>rooms = {{1},{2},{3},{}};
    cout<<(canVisitAllRooms(rooms)?"true":"false")<<endl;
    return 0;
}