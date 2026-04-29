#include<bits/stdc++.h>
#define ll long long
using namespace std;


long long maximumScore(vector<vector<int>>& g)
{

    int m = g.size(),n = g{0}.size();

    /*


    select any cell of indices (i,j) and color black all the cells of jth column from top to bottom


    Score = sum of all g[i][j] that i,j is white and has horizontally adjacent black cell 


    // color the cell adjacent to some big number black
    
    */




}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>>g = {{0,0,0,0,0},{0,0,3,0,0},{0,1,0,0,0},{5,0,0,3,0},{0,0,0,0,2}};
    cout<<maximumScore(g)<<endl;

    return 0;
}