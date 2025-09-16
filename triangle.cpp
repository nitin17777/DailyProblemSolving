#include<iostream>
#include<vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
    int n = triangle.size();

    //we have to return the minimum path sum ot the given triangle
    //or just add the smallest element from each row

    //from the second last row onwards
    for(int row = n-2; row >= 0; row--)
    {
        for(int col = 0; col < triangle[row].size(); col++)
        {
            triangle[row][col] += min(triangle[row+1][col] , triangle[row+1][col+1]);
        }
    }
    return triangle[0][0];

}

int main()
{

    vector<vector<int>>triangle = {
        {2},{3,4},{6,5,7},{4,1,8,3}
    };

    int ans = minimumTotal(triangle);

    cout<<ans<<endl;

    return 0;
    
}
