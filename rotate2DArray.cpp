//rotating given array by 90 degree clockwise.


#include<iostream>
#include<vector>
using namespace std;


//Not studied
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const int& num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void rev(vector<int>&row)
{
    int start = 0;
    int end = row.size()-1;

    while(start<end)
    {
    swap(row[start],row[end]);

    start ++;
    end --;
    }
}
vector<vector<int>>rotate(vector<vector<int>>&matrix)
{
    int n = matrix.size();

//Algo:-> swap i and j index of all elements 
        //->and then reverse all rows


        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);

            }

        }

        for(int i = 0; i<n; i++)
        {
            rev(matrix[i]);

        }

        return matrix;
}

int main()
{
    vector<vector<int>>arr = {

        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> rotated = rotate(arr);

    printMatrix(rotated);

    return 0;
}

/*
Output:

7,4,1
8,5,2
9,6,3

*/