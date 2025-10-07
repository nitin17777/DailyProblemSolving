#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    // town judge trusts nobody
    // everybody trusts the town judge and only such person exists

    // trust[i] = [ai,bi] =>ai trusts person bi
    // return -1 otherwise

    if (n == 1)
        return 1;

    vector<int> trustsOut(n + 1, 0), trustedBy(n + 1, 0);

    for (auto &t : trust)
    {
        int a = t[0], b = t[1];

        trustsOut[a]++;
        trustedBy[b]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (trustsOut[i] == 0 && trustedBy[i] == n - 1)
            return i;
    }
    return -1;
}

int main()
{
    vector<vector<int>> trust = {{1, 2}};
    cout << findJudge(2, trust) << endl;

    return 0;
}