#include<iostream>
#include<vector>

using namespace std;


void setZeroes(vector<vector<int>>& matrix)
{

    //if an element is zero ,set the entire row and column to zero as well
    


}


int main()
{
    vector<vector<int>>matrix = {
    {1,1,1}, {1,0,1}, {1,0,1}
    };

    setZeroes(matrix);

    for(auto mat:matrix)
    {
        for(auto ma:mat)
        {
            cout<< ma <<" ";
        }
        cout<<endl;
    }
    return 0;
    
}
