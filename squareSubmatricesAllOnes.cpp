#include<iostream>
#include<vector>
using namespace std;


int countSquares(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();



    
}

int main()
{

    vector<vector<int>>matrix = {
        {0,1,1,1},{0,1,1,1},{0,1,1,1}        
    };

    int ans = countSquares(matrix); 

    cout<<ans<<endl;

    return 0;
    
}
