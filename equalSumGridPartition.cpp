#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool canPartitionGrid(vector<vector<int>>& g)
{
    int m = g.size(),n = g[0].size();

    /*
    Determine if it is possible to make onne horizontal or vertical cut on grid such that :
    Both resulting sections are non empty
    And sum of elements in both sections are equal 

    Determine if such partition exists

    */

    ll total = 0;
    for(auto &row:g)
    {
        for(auto &x:row)total+=x;
    }

    //Imoossible if total sum is odd
    if(total%2 != 0)return false;

    ll half = total/2;

    //Horizontal cut
    ll sum = 0;
    for(int i = 0;i<m-1;i++)
    {
        //At every col checking if we were successful in getting exact sum
        for(int j = 0;j<n;j++)
        {
            sum += g[i][j];
        }

        if(sum == half)return true;
    }

    //Now vertical cut

    sum = 0;

    for(int j = 0;j<n-1;j++)
    {
        for(int i = 0;i<m;i++)
        {
            sum += g[i][j];
        }
        if(sum == half)return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,4},{2,3}};
    cout<<(canPartitionGrid(g)?"True":"False")<<endl;

    return 0;
}