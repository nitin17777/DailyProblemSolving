#include<iostream>
#include<vector>

using namespace std;

int main()
{

    vector<vector<int>> grid =
    {
        {2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}
    };
    cout<<len(grid)<<endl;

    return 0;
    
}


