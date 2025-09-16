#include<iostream>
#include<vector>
using namespace std;


vector<int>spiral(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    int count= 0;
    int total = row * col; //total elements
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col-1;

    vector<int>ans;



    while(count<total)
    {

        //printing starting row
        for(int index = startingRow; count < total && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

//printing ending column
        for(int index= startingRow; count < total &&index <= endingRow;index++)
        {
            ans.push_back(matrix[index][endingCol]);
            count++;   
        }     
        endingCol--;

        //printing ending row
        for(int index = endingCol; count<total && index >= startingCol; index--)
        {
            ans.push_back(matrix[endingRow][index]);
        }
        
        endingRow--;

        //printing starting column
        for(int index= endingRow; index >= startingRow && count <total ; index--)
        {
            ans.push_back(matrix[index][startingCol]);
            count++;
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
   vector< vector<int>>arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
        };

        vector<int>ans = spiral(arr);
        for(auto & num : ans)
        {
            cout<<num<<" ";

        }
        cout<<endl;

        
        
        return 0;

}