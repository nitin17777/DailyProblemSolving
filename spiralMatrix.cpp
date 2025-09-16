#include<iostream>
#include<vector>

using namespace std;

vector<int>spiral(vector<vector<int>>arr )
{
    // we havee to print the given array in spiral form
    //firstly 1st row ->then last col->then last row->then first col->then 2nd row 
    
}

int main()
{
    vector<vector<int>>arr= 

    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int>ans =spiral(arr);

    for(auto an : ans)
    {
        cout<<an<<" ";
    }

    cout<<endl;
    return 0;

}