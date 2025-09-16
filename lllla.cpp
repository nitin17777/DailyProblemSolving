#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>sortMatrix(vector<vector<int>>grid)
{
    int n = grid.size();

    //collect all diagonal elements 

    unordered_map<int,vector<int>>diagMap;


    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            diagMap[i-j].push_back(grid[i][j]);
        }
    }
    //sort 

    for(auto&[key,vec] : diagMap)
    {
        if(key>=0)
        {
            sort(vec.begin(),vec.end(),greater<int>());

        }

        else
        {
            sort(vec.begin(),vec.end());
      
        }
    }
    //final push sorted array 

    unordered_map<int,int>index;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int key = i-j;
            grid[i][j]= diagMap[key][index[key]++];
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


