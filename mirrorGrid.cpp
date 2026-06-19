#include<bits/stdc++.h>
#define ll long long
using namespace std;

//In one operation we can flip the grid 
int solve(vector<string>&grid,int n)
{

    //1 operation = flip any cell of the grid
    //How many operations to make that req square

    //The final square should be fully symmetric

    int ans = 0;


    for(int i = 0;i<(n+1)/2;i++)
    {
        for(int j = 0;j<n/2;j++)
        {
            int ones = 0;
            
            //After one rotation of 90 degrees: i,j changes to j,n-i-1
            ones += grid[i][j] -'0';

            ones+=grid[j][n-i-1] -'0';

            ones += grid[n-i-1][n-j-1] -'0';

            ones+= grid[n-j-1][i] -'0';

            ans+=min(ones,4-ones);
        }
    }

    return ans;

}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<string>grid(n);
        for(int i =0;i<n;i++)
        {
            cin>>grid[i];
        }
        cout<<solve(grid,n)<<'\n';   
    }

    return 0;
}