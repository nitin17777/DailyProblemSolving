#include<bits/stdc++.h>
#define ll long long
using namespace std;

int m,n;
vector<pair<int,int>>dir =
{
    {-1,-1}, {-1,0}, {-1,1},
    {0,-1},          {0,1},
    {1,-1},  {1,0},  {1,1}
};


void dfs(vector<vector<char>>& board, int r, int c)
{
   if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E')return; 

   int mines = 0;

   for(auto [dx,dy]:dir)
   {
        int nr = r+dx;
        int nc = c+dy;

        if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M')mines++;
    }
        
    if(mines>0)
    {
        board[r][c] = mines+'0';
        return;
    }

    board[r][c] = 'B';

    for (auto [dx, dy] : dir) dfs(board, r + dx, c + dy);
    
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
{
    m = board.size();
    n = board[0].size();

    int r = click[0],c=click[1];

    if(board[r][c] == 'M')
    {
        board[r][c]='X';

        return board;
    }

    dfs(board,r,c);
    return board;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>>board= {{'E','E','E','E','E'},{'E','E','M','E','E'},{'E','E','E','E','E'},{'E','E','E','E','E'}};
    vector<int>click = {3,0};

    vector<vector<char>>ans = updateBoard(board,click);
    for(auto& row:ans)
    {
        for(auto&x:row)cout<<x<<' ';

        cout<<endl;
    }
    cout<<endl;

    return 0;
}