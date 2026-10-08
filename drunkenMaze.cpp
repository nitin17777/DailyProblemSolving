#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    int si=-1,sj=-1;
    int ei=-1,ej = -1;

    vector<vector<char>>a(n,vector<char>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];

            if(a[i][j] == 'S')
            {
                si = i;
                sj = j;
            }

            if(a[i][j] == 'T')
            {
                ei = i;
                ej = j;
            }
        }
    }

    //We can consecutively move more than 3 steps in one direction


    //Min steps to reach end position from start position else return -1
    // # means a wall and . means free space to move


    return 0;
}