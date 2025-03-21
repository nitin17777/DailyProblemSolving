#include<iostream>
using namespace std;


void printSum(int arr[][4],int row,int col )
{
     cout<<"Printing Sum: " <<endl;
     for(int r = 0;r<row;r++)
     
     {
        int sum = 0;
        for(int c = 0;c<col;c++)
        {
            sum +=arr[r][c];
            cout << "Row " << r + 1 << " sum: " << sum << endl;

        }
     }
}

bool isPresent(int arr[][4],int target,int row,int col)

{
    for(int row =0;row<3;row++)

    {
        for(int col = 0;col<4;col++)
        {

        if(arr[row][col] == target)
        
        {
            return 1;

        }
        }
    }
    return 0;

}

int main()
{

    int arr[3][4];

    for(int row = 0;row<3;row++)
    {
        for(int col = 0;col<4;col++)
        {
            cin>>arr[row][col];

        }
    }
    return 0;
    }


