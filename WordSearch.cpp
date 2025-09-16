#include<iostream>
#include<vector>
#include<string>
using namespace std;

    bool dfsHelper(vector<vector<char>>& board,string & word,int i , int j,int index)
    {
        int rows = board.size();
        int cols = board[0].size();

        //if the whole word is found
        if(index == word.length())
        return true;

        //making sure that we don't go out of bounds and current char
        if(i<0 || i>rows || j<0 || j>cols || board[i][j] != word[index])
        return false;

        //Now marking current cell as visited
        char temp = board[i][j];//just to erase the marker after checking is done
        board[i][j] = '#';

        bool found = dfsHelper(board,word,i+1,j,index+1) || 
                     dfsHelper(board,word,i-1,j,index+1) || 
                     dfsHelper(board,word,i,j+1,index+1) || 
                     dfsHelper(board,word,i,j-1,index+1);

                     board[i][j] = temp;

                     return found;

    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for(int i =0; i<rows; i++)
        {
            for(int j =0; j<cols; j++)
            {
                if(dfsHelper(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }

int main()
{
    vector<vector<char>>board = {
         {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word ="ABCCED";


    if(exist(board,word))
    cout<<"True"<<endl;

    else
    cout<<"False"<<endl;



    return 0;
    
}
