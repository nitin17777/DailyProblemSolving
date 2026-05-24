#include<bits/stdc++.h>
#define ll long long
using namespace std;

int matrixScore(vector<vector<int>>& g)
{
    int m = g.size(),n = g[0].size();

    /*

    In each move we can toggle values of any row or column

    Return the highest possible score after making any number of moves
    */

    //for each row : if number of 0  > number of 1 -> toggle
    //And same for col


    //rows first


    //If first number of row is zero, toggle all elements of the row
    for(int i = 0;i<m;i++)
    {
        if(g[i][0] == 0)
        {
            for(int j = 0;j<n;j++)
            {
                if(g[i][j] == 0)g[i][j] = 1;
                else g[i][j]=0;
            }
        }
    }

    //for each col now :Check if cnt0 > cnt1 -> If yes -> toggle all elemnents in the col

    for(int j = 0;j<n;j++)
    {
        int cnt1=0,cnt0=0;
        for(int i = 0;i<m;i++)
        {
            if(g[i][j] == 0)cnt0++;
            else cnt1++;
        }

        if(cnt0>cnt1)
        {
            for(int i = 0;i<m;i++)
            {
                if(g[i][j] == 0)g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
    }

    //Now simply count the answer
    int ans = 0;

    for(int i = 0;i<m;i++)
    {
        int k = n;
        for(int j = 0;j<n;j++)
        {
            ans += g[i][j] * pow(2,k-1);
            k--;
        }
    }
    return ans;  
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};

    cout<<matrixScore(g)<<endl;

    return 0;
}