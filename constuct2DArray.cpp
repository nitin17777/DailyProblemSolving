#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int row, int column)
{

    //construct a 2d array of m rows and n columns  using given 1d array 


    if(m*n != original.size() )
    {
        cout<<"Invalid Size."<<endl;

    }

    for(int i = 0;i<original.size();i++)
    {
        int row = i/col;
        int col = i%col;

        result[row][col] = original[i];


    }
    }

int main()

{




    return 0;

}