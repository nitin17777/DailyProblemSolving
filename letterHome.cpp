#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &arr, int s)
{
    // we are initially at pos = s on X axis,  we can perform exactly one of the two actions

    // either position + 1 or position-1
    // steps will be considered succesful if during the entire journey we visit each xi on X axis atleast once

    // determine the min steps in any successful sequence of steps
}

int main()
{

    vector<int> arr = {1, 2, 3, 9, 10, 11};

    cout << solve(arr, 6) << endl;

    return 0;
}