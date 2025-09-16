#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col, vector<vector<int>>&board, int val)
{
    for(int i = 0; i<board.size(); i++)
    {
        //row and column check

        if(board[row][i] == val ||board[i][col] == val )
        {
            return false;
        }

        //3*3 matrix check

        int startRow = 3 * (row/3);
        int startCol = 3 * (col/3);

        for(int i =0; i <3 ; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[startRow + i][startCol + j] == val)
                
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board)
{
    int n = board.size();
    for(int row = 0; row<n; row++)
    {
        for(int col = 0;col<n; col++)
        {

            //empty cell

            if(board[row][col] == 0)
            {
                for(int val = 1 ; val<=9; val++)
                {
                    if(isSafe(row,col,board,val))
                    {
                       board[row][col] = val;


                       //recursive call
                       bool possibleSolution = solve(board);
                       if(possibleSolution)
                       {
                        return true;

                       }

                       else
                       {
                        //bactrack
                        board[row][col] = 0;
                       }
                    }
                }
                return false;
            }
        }
    }
    return true;


}

void solveSudoku(vector<vector<int>>& sudoku)
{
    //each row must contain all numbers from 1-0 exactly once
    
    //each column must contain all numbers from 1-0 exactly once

    //each digit from 1-9 must occur exactly once in each of the 9, 3*3 subgrids of the grid

    solve(sudoku);
}


int main()
{
    vector<vector<int>>sudoku = {

    {0, 7, 5, 0, 0, 3, 0, 2, 0},
    {0, 0, 0, 0, 0, 1, 0, 6, 0},
    {0, 0, 0, 0, 2, 0, 7, 3, 0},
    {0, 0, 0, 0, 8, 4, 0, 0, 9},
    {7, 0, 0, 8, 0, 0, 3, 1, 0},
    {1, 0, 4, 0, 0, 0, 0, 0, 0},
    {0, 0, 9, 0, 7, 0, 0, 0, 0},
    {0, 0, 0, 8, 0, 0, 6, 0, 0},
    {3, 5, 6, 2, 0, 0, 0, 4, 0}
    };
    
    solveSudoku(sudoku);

    for(auto row: sudoku)
    {
        for(auto num:row)
        {
            cout<< num <<" ";
        }
        cout<<endl;
    }
    

    return 0;
}
