#include<bits/stdc++.h>
using namespace std;


int ops(vector<vector<int>>grid , int x)
{

    // we have to return min no. of operations to make the given grid uni-value grid, if not possible return -1

    // we can repeat operations as per our wish


    //if difference between any two numbers is not divisble by x ,we can never reach each other by using given x
    int m = grid.size(); // rows
    int n = grid[0].size(); //columns


    vector<int>flattened;


    int modVal = grid[0][0] % x;
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            flattened.push_back(grid[i][j]);

            if(grid[i][j] % x != modVal) // because remainder must be same for all elements in the grid
            {
                return -1;

            }
        }
    }
//so as to get the median of this array
    sort(flattened.begin(),flattened.end());

    int median = flattened[flattened.size()/ 2];

    int operations = 0;

    for(auto num: flattened)
    {
        operations += abs(num - median)/ x;


    }

    return operations;
}

int main()
{
    vector<vector<int>>arr ={
        {8,2},{4,6}
    };
    int x= 2;


    int num= ops(arr,x);

    cout<<num<<endl;


    
}