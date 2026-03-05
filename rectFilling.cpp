#include<bits/stdc++.h>
using namespace std;


bool solve(vector<vector<int>>&a)
{
    int n  =a.size(),m= a[0].size();

    //Determine if it's possible to make all the squares of grid of same color

    bool topSame = true,bottomSame = true;

    //Checking the top row
    for(int j = 1;j<m;j++)
    {
        if(a[0][j] != a[0][0])topSame = false; 
    }


    //Checking the bottom row now
    for(int j = 1;j<m;j++)
    {
        if(a[n-1][j] != a[n-1][0])bottomSame = false; 
    }

    if(topSame && bottomSame && a[0][0] != a[n-1][0])return false;


    bool left = true, right = true;

    //Left and right col
    for(int i = 1;i<n;i++)
    {
        if(a[0][0] != a[i][0])left = false;
        if(a[0][m-1] != a[i][m-1])right = false; 
    }
    if (left && right && a[0][0] != a[0][m-1]) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>>a(n,vector<int>(m));


        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char ch;
                cin>>ch;

                if(ch == 'W')a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        
        cout<<(solve(a)?"Yes":"No")<<endl;
    }
    return 0;
}