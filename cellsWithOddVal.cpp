#include<bits/stdc++.h>
#define ll long long
using namespace std;

int oddCells(int m, int n, vector<vector<int>>& indices)
{
    vector<int>row(m,0),col(n,0);

    for(auto & x:indices)
    {
        row[x[0]]++;
        col[x[1]]++;
    }

    int oddRows = 0,oddCols = 0;

    for(int x : row)if(x & 1) oddRows++;

    for(int x : col)if(x & 1) oddCols++;

    return oddRows*(n-oddCols) + (m-oddRows)*oddCols;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<vector<int>>idx = {{0,1},{1,1}};
   cout<<oddCells(2,3,idx)<<'\n';

    return 0;
}