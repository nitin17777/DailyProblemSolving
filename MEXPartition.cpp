#include <iostream>
#include <vector>
using namespace std;

int score(vector<int> arr)
{
    // find the minimum MEX out of all multiset

    unordered_map<int, int> freq;
    for (auto &an : arr)
    {
        freq[an]++;
    }

    int mex = 0;
    while (true)
    {
        if (freq.count(mex))
        {
            mex++;
            continue;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2};
    cout << score(arr) << endl;

    return 0;
}