#include<iostream>
#include<vector>
using namespace std;


void dfs(vector<vector<int>>& heights,vector<vector<int>>&ocean,int i ,int j)
{
    int m = heights.size();
    int n = heights[0].size();
    
    ocean[i][j] = 1;//mark current cell as visited for this ocean

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    for(auto&d : dirs)
    {
        int x = i+ d[0];
        int y = j + d[1];
        
        if(x<0 || y<0 || x >= m || y>=n ||ocean[x][y])continue;


        if(heights[x][y] < heights[i][j]) continue;

        dfs(heights,ocean,x,y);
    }
}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    // m*n island that borders both the ocean
    //each cell represents height above sea level
    //water can flow to adjacent cell if neighbouring cell's height is less than or equal to the current cell's height

    //return 2d list of grid coordinates where rain water can flow
    if(heights.empty())return {};

    int m = heights.size(), n= heights[0].size();
    

    //to mark the reachable cells by oceans
    vector<vector<int>>pacific(m,vector<int>(n,0));
    vector<vector<int>>atlantic(m,vector<int>(n,0));

    //DFS from left to right => from top row +left column
    for(int i = 0 ; i < m;i++)
    {
        dfs(heights,pacific,i,0);//left edge ->pacific
        dfs(heights,atlantic,i,n-1);//right edge
    }

    //from top to bottom
    for(int j = 0 ; j < n;j++)
    {
        dfs(heights,pacific,0,j);//left edge ->pacific
        dfs(heights,atlantic,m-1,j);//right edge ->atlantic

    }

    //getting common paths from both and will take their intersection as our final answer
    vector<vector<int>>result;

    for(int i = 0 ;i<m;i++)
    {
        for(int j=0 ;j<n;j++)
        {
            if(pacific[i][j] && atlantic[i][j])
            result.push_back({i,j});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>>heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    vector<vector<int>>ans = pacificAtlantic(heights);

    for(auto&an: ans)
    {
        for(auto & a : an)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;

}