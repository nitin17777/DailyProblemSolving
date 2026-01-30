#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[51][51][51];
int M, N;

int solve(int r, int c, int moves)
{
    // Count one path if ball goes out of grid
    if (r < 0 || r >= M || c < 0 || c >= N)
        return 1;

    if (moves == 0)
        return 0;

    if (dp[r][c][moves] != -1)
        return dp[r][c][moves];

    long long ans = 0;

    // Move in all 4 directions
    ans += solve(r + 1, c, moves - 1); // down
    ans += solve(r - 1, c, moves - 1); // up
    ans += solve(r, c + 1, moves - 1); // right
    ans += solve(r, c - 1, moves - 1); // left

    return dp[r][c][moves] = ans % MOD;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{

    /*


    Ball is initially at (startRow,startCol) and we can move ball to one of the four adjacent cells

    We can apply at most maxMove moves to the ball

    Return the number of paths to move the ball out of the grid boundary

    */

    M = m;
    N = n;

    /*
    We are basically doing this with memset

    for(int i=0;i<51;i++)
    for(int j=0;j<51;j++)
    for(int k=0;k<51;k++)
        dp[i][j][k] = -1;

    memset(address, value, size_in_bytes);

    */
    memset(dp, -1, sizeof(dp));

    return solve(startRow, startColumn, maxMove);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << (findPaths(2, 2, 2, 0, 0)) << endl;

    return 0;
}