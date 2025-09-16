#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>generate(int numRows)
// we have to return the enitre pascal tree
{

    vector<vector<int>>triangle;

    for(int i = 0; i<numRows; i++)
    {
        vector<int>row(i+1,1); // creating a row of size (i+1) filled with 1 and we will update the remaining middle elements later

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
    auto rows = 5;

    vector<vector<int>>ans = generate(rows);

    for(auto row: ans)
    {
        for(auto num: row)
        {
            cout<<num<<" ";

        }
        cout<<endl;
        
    }


    return 0;

}