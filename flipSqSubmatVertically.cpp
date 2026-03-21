#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>>& g, int x, int y, int k)
{

    int m  = g.size(),n = g[0].size();

    //Flip the submatrix by reversing the order of it's row vertcially 

    for(int i = 0; i<k/2; i++)
    {
        int topRow = x+i;
        int bottomRow = x+k-i-1;
        
        for(int j = y; j<y+k; j++)
        {
            swap(g[topRow][j], g[bottomRow][j]);
        }
    }

    return g;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    vector<vector<int>>ans = reverseSubmatrix(g,1,0,3);
    for(auto &an:ans)
    {
        for(auto & x:an)cout<<x<<" ";

        cout<<endl;
    }
    return 0;
}