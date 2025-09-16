#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int>>& ans, vector<vector<int>>& board, int n)
{
    vector<int> temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

//can be optimised more

bool isSafe(int row, int col, vector<vector<int>>& board, int n)
{
    int x = row;
    int y = col;

    // check left side
    while(y >= 0)
    {
        if(board[x][y] == 1)
            return false;
        y--;
    }

    // check upper left diagonal
    x = row;
    y = col;
    while(x >= 0 && y >= 0)
    {
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // check lower left diagonal
    x = row;
    y = col;
    while(x < n && y >= 0)
    {
        if(board[x][y] == 1)
            return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n)
{
    if(col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; // backtrack
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}

int main()
{
    int n = 9;
    vector<vector<int>> ans = nQueens(n);

    cout << "Total solutions: " << ans.size() << "\n\n";

    for(auto& num : ans)
    {
        for(int i = 0; i < n * n; i++)
        {
            if(i % n == 0 && i != 0)
                cout << endl;
            cout << (num[i] == 1 ? "Q " : ". ");
        }
        cout << "\n\n";
    }

    return 0;
}
