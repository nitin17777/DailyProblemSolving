#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    //in pascal triangle each number is sum of above two directly numbers 
    

    vector<vector<int>>triangle;

      for(int i =0; i <numRows; i++)
      {
        vector<int>row(i+1, 1);

        for(int j = 1; j<i; j++)
        {
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];

        }
        triangle.push_back(row);
      }
      return triangle;
}

int main()
{

    int numRows = 5;
    vector<vector<int>>ans = generate(numRows);

    for(auto& an : ans)
    {
        for(auto& a : an)
        {
            cout<<a<<" ";

        }
        cout<<endl;

    }
    return 0;
}