#include<bits/stdc++.h>
using namespace std;

int countBattleships(vector<vector<char>>& b)
{
    int m = b.size(), n = b[0].size();

    /*

    These ships can be placed only horizontally or vertically on the b means only 1*k or k*1


    Return the number of battleship on the b
    */


    //Find all the vertical or horizontal consecutive blocks

    //Each battleship has unique starting cell 

    //

    int cnt = 0;

    for(int i =0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(b[i][j] == 'X')
            {
                if(i == 0 || b[i-1][j] == '.') && (j == 0 || b[i][j-1] == '.')
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>b = 
    return 0;
}