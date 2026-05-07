#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& g)
{
    int m = g.size(),n= g[0].size();

    //Return the box after it is rotated 90 degrees clockwise
    //Stones rest on top of each other and on other stones

    //Return the rotated box of n*m size



    for(int i =0;i<m;i++)
    {
        int empty = n-1;

        for(int j = n-1;j>=0;j--)
        {
            if(g[i][j] == '*')empty = j-1;

            else if(g[i][j] == '#')
            {
                swap(g[i][j], g[i][empty]);
                empty--;
            }
        }
    }


    vector<vector<char>>ans(n,vector<char>(m));
    //Rotating now
    for(int i =0 ;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            ans[j][m-1-i]  = g[i][j];
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>g = {{'#','.','*','.'},{'#','#','*','.'}};
    vector<vector<char>>ans = rotateTheBox(g);

    for(auto & x:ans)
    {
        for(auto & y:x)cout<<y<<' ';

        cout<<endl;

    }



    return 0;
}