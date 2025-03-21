#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isSafe(int x,int y ,int n, vector<vector<int>>&visited ,vector<vector<int>>&m)
{
    if((x>=0 && x<n ) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1)
    {
        return true;

    }
    else
    {
        return false;

    }
}

void solve(vector<vector<int>> &m,int n,vector<string>&ans,int x,int y,vector<vector<int>> visited , string path)
{
    //base case - when reached x,y
    if(x == n-1 &&y == n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;



    int newx,newy;

    //we have four directional choices

//down
    newx = x+1;
    newy = y;
    if(isSafe(newx,newy,n,visited,m))
    {
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }


    //left

    newx = x;
    newy = y-1;
    if(isSafe(newx,newy,n,visited,m))
    {
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }


//right
    newx = x;

    newy = y+1;
    if(isSafe(newx,newy,n,visited,m))
    {
    
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }


    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx,newy,n,visited,m))
    {
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
}

vector<string> findPath(vector<vector<int>>& m , int n)
{
    vector<string>ans;
    int srcx = 0;
    int srcy = 0 ;

    if(m[0][0] == 0 || m[n-1][n-1] == 0)
    {
        return ans;
    }

    vector<vector<int>>visited(n,vector<int>(n,0));

    string path = "";
    solve(m,n,ans,srcx,srcy,visited,path);


    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    int n = 4;


    vector<vector<int>>arr = {
        {1,0,0,0},
        {1,1,0,0},
        {0,1,1,0},
        {1,1,1,1}
    };

    vector<string>paths = findPath(arr,n);

    if (paths.empty()) 
    {
        cout << "No paths found!" << endl;
    } else 
    {
        cout << "Possible paths:\n";
        for (string path : paths) {
            cout << path << endl;
        }
    }
    return 0;
}

