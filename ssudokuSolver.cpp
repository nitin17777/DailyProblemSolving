#include<iostream>
#include<vector>

using namespace std;


bool isSafe(int row,int col,vector<vector<char>>board,int val)
{

    //Row and column check
    for(int i = 0;i<board.size();i++)
    {
        if(board[row][i] == ('0'+val) || board[i][col] == ('0'+val))
        return false;
    }

    //3*3 check

    int startRow  = 3 * (row/3);
    int startCol = 3 * (col/3);

    for(int i =0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(board[startRow + i][startCol + j] ==('0'+val))
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>&board)
{
    int n = board.size();

    for(int row = 0;row<n;row++)
    {
        for(int col =0;col<n;col++)
        {

            if(board[row][col] == '.')
            {
                for(int val = 1;val<=9;val++)
                {
                    if(isSafe(row,col,board,val))
                    {
                        board[row][col] = val +'0';
                    

                    bool possibleSolution = solve(board);


                    if(possibleSolution)return true;
                    else
                    {
                        board[row][col] = '.';
                    }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void solveSudoku(vector<vector<char>>& board)
{

    solve(board);

}

int main()
{
    vector<vector<char>>board = 
    {
        {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);

    for(auto & sud : board)
    {
        for(auto&su :sud)
        {
            cout<<su<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
    
}
