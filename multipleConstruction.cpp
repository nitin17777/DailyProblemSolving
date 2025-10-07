#include <iostream>
#include <vector>

using namespace std;

vector<int> construct(int n)
{
    // we have to construct an array of length 2n such that each integer from i to n appears exactly twice in the array

    // for each x ,distance between it's two occurrence will be multiple of x

    // construct the final array

    vector<int> ans(2 * n, 0);

    for (int x = n; x >= 1; x--)
    {
        }
    return ans;
}

int main()
{
    vector<int> ans = construct(2);
    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}
