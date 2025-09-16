#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
    //if frequency of number in it's corresponding row and column is greater than 1 , return false + Each 3*3 subgrid contains one digit at most once only

    for(int i = 0;i<9;i++)
    {
        unordered_set<char>seenRow,seenCol;

        for(int j =0; j <9; j++)
        {

            //Row check
            if(board[i][j] != '.')
            {
                if(seenRow.find(board[i][j]) != seenRow.end())
                {
                    return false;
                }

                seenRow.insert(board[i][j]);

            }

            //Column check
            if(board[j][i] != '.')
            {
                if(seenCol.find(board[j][i]) != seenCol.end())
                return false;

                seenCol.insert(board[j][i]);
            }
        }
    }

    //Now 3*3 check

    for(int boxRow = 0;boxRow<3;boxRow++)
    {
        for(int boxCol =0;boxCol<3;boxCol++)
        {
            unordered_set<char>seenBox;

            for(int i = 0;i<3;i++)
            {
                for(int j = 0;j<3;j++)
                {
                    char val = board[boxRow * 3 + i][boxCol *3 +j];
                    if(val != '.')
                    {
                        if(seenBox.find(val) != seenBox.end())
                        return false;

                        seenBox.insert(val);
                    }
                }
            }

        }
    }


    return true;  
}


int main()
{
    vector<vector<char>>board= 
    {
        {'.','.','4','.','.','.','6','3','.'},{'.','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','9','.'},{'.','.','.','5','6','.','.','.','.'},{'4','.','3','.','.','.','.','.','1'},{'.','.','.','7','.','.','.','.','.'},{'.','.','.','5','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'}
    };
    
    /*{
         {'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}
    };*/

    cout<<(isValidSudoku(board)? "true" : "false")<<endl;

    return 0;

}