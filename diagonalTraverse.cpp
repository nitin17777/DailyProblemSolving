#include<iostream>
#include<vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    //we have to traverse through all diagonal elements without lifting our pen say for instance

    if(mat.empty())return {};
    int m = mat.size();
    int n =mat[0].size();

    vector<int>result;

    int i = 0,j=0;

    bool up = true;

    while(result.size() < m*n)
    {
        result.push_back(mat[i][j]);

        if(up == true)
        {
            if(j == n-1)//Boundary case : When we are at rightmost edge
            {
                i++;
                up =false;

            }
            else if(i == 0)//when we are at leftmost edge
            {
                j++;
                up=false;

            }
            else//normally moving up
            {
                i--;
                j++;
            }
        }
        else
        {
            if(i == m-1)
            {
                j++;
                up = true;
            }
            else if(j==0)
            {
                i++;
                up = true;
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>>mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };

    vector<int>ans = findDiagonalOrder(mat);

    for(auto&dia : ans)
    {
        cout<<dia<<" ";
    }
    cout<<endl;

    return 0;
    
}
