#include <iostream>
#include <vector>

using namespace std;

bool canReorderDoubled(vector<int> &arr)
{
    int n = arr.size();

    // return true if it is possible to reorder arr such that : arr[2*i+1] =2 * arr[2*i] for i< n/2
}

int main()
{
    vector<int> arr = {3, 1, 3, 6};
    cout << canReorderDoubled(arr) ? "true" : "false" << endl;
    return 0;
}
