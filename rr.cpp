#include<bits/stdc++.h>
using namespace std;


// a rat is stuck in a maze, '1' means there is a path and '0' means the path is blocked there.Now we have to find the path which will make the rat reach the end of given maze.

bool isSafe( vector<vector<int>>& visited , vector<vector<int&m)
{
    int x,y,n;

    //checking whether if the new positon is within bounds or not.
    if(x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0 &&m[x][y] = 1)
    return true;
    else
    return false;
}

void solve(vector<vector<int>>&m, vector<string>&ans, vector<vector<visited)




int main()
{
    vector<vector<int>>arr = {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,1,0},
        {1,1,1,1}
    };

    if(paths.empty())
    {
        cout<<"NO path found."<<endl;

    }

    else
    {
        cout<<"Possible Path: ";
        for(string path : paths)
        {
            cout<<path<<endl;
        }
    }
    return 0;

}