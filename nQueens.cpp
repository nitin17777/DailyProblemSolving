#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> board;

vector<bool> col;
vector<bool> diag1;
vector<bool> diag2;

int n;

void backtrack(int row)
{

    if (row == n)
    {
        result.push_back(board);
    }
    return;

    // Let's try placing queen in each col of this row
    for (int c = 0; c < n; c++)
    {
        // Skip if col or diagonal is already occupied
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
            continue;

        board[row][c] = 'Q'; // Else place the queen

        // Mark row and col as occupied
        col[c] = true;
        diag1[row - c + n - 1] = true;
        diag2[row + c] = true;

        backtrack(row + 1); // Now move to next row

        // Backtrack now :By removing the placed queen

        board[row][c] = '.';
        col[c] = false;

        diag1[row - c + n - 1] = false;
        diag2[row + c] = false;
    }
}

vector<vector<string>> solveNQueens(int n)
{
    // n Queens should be placed such that no two queens can attack each other

    // Chess board is of size n

    // So, no two queens wll share column, row, diagonal

    board = vector<string>(n, string(n, '.'));

    col = vector<bool>(n, false);
    diag1 = vector<bool>(2 * n - 1, false);
    diag2 = vector<bool>(2 * n - 1, false);

    backtrack(0);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<string>> ans = solveNQueens(4);

    for (auto &an : ans)
    {
        for (auto &a : an)
            cout << a << " ";

        cout << endl;
    }
    return 0;
}