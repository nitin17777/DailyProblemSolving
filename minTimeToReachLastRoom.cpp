#include<iostream>
#include<vector>
using namespace std;

int minTime(vector<vector<int>>& moveTime)
{
    //moving between room takes exactly 1 second
    //we have to return the minimum time to reach room[n-1][m-1]

}

int main()
{
    vector<vector<int>>moveTime = {
        {0,4},{4,4}
    };

    int ans = minTime(moveTime);

    cout<<ans<<endl;


    return 0;


}