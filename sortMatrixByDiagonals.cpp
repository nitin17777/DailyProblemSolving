#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
{
    //return the matrix such that : Diagonals in bottom left triangle, including middle diagonal are sorted in non increasing order

    //Also diagonals in top right triangle are sorted in non decreasing order
    int n = grid.size();

    unordered_map<int,vector<int>>diagMap;

    //collect elements for each diagonal 
    for(int i =0; i < n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            diagMap[i-j].push_back(grid[i][j]);
        }
    }

    //now sorting each diagonal
    for(auto&[key,vec] : diagMap)
    {
        //if elements below diagonal 
        if(key>=0)
        {
            sort(vec.begin(),vec.end(), greater<int>()); //for descendig order sorting
        }
        else//elements above diagonal
        {
            sort(vec.begin(),vec.end());
        }
    }

    //now placing back sorted elements

    unordered_map<int,int>index;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int key = i-j; 
            grid[i][j] = diagMap[key][index[key]++];
        }
    }
    return grid;    
}

int main()
{
    vector<vector<int>>grid =
    {
        {1,7,3},{9,8,2},{4,5,6}
    };

    vector<vector<int>>ans = sortMatrix(grid);
    for(auto&an:ans){
        for(auto&a :an)
        {
            cout<<a<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
    
}
