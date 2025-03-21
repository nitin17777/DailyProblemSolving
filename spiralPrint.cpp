#include<iostream>
#include<vector>
using namespace std;


vector<int>spiral(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();


    int count= 0;
    int total = row*col;

    int startingRow = 0;
    int endingCol = 0;
    int endingRow =row - 1;
    int endingCol = col-1;


    while(count<total)
    {
        for(int index = startingCol; count<total && index <= endingCol; index++)
        {
            ans.pushback(matrix[startingRow][index]);
        }

        startingRow++;

//printing starting row
        for(int index= startingRow; index < endingRow; index++)
        {

            ans.push_back(matrix[index][endingCol]);


        
        endingCol--;
        }

        //printting ending row

        for(int index = endingCol;index>=startingCol;index--;)
        {
            ans.push_back(matrix[index][index]);
        }
        
        endingRow--;

        //printing starting column

        for(int index= endingRow; index >= startingRow; index++)
        {
            ans.push_back(matrix[index][starting col]);
            col++;
        }

        startingCol++;
        }
        return ans;
}

/*Printing starting row
->Then printing ending column
-then ending row
->then 

*/
int main()
{

    vector<int>arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };

        cout<<spiral<<endl;
    return 0;

}