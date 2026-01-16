#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
{
    /*
    Return the max area of square field that can be formed by removing some fences or return -1 if it is impossible to remove the fences

    */

    vFences.push_back(1);
    vFences.push_back(n);

    hFences.push_back(1);
    hFences.push_back(m);

    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    // Storing all possible horizontal Gaps
    unordered_set<int> hGaps;
    for (int i = 0; i < hFences.size(); i++)
    {
        for (int j = i + 1; j < hFences.size(); j++)
        {
            hGaps.insert(hFences[j] - hFences[i]);
        }
    }

    long long maxSide = -1;

    for (int i = 0; i < vFences.size(); i++)
    {
        for (int j = i + 1; j < vFences.size(); j++)
        {
            int gap = vFences[j] - vFences[i];
            if (hGaps.count(gap))
            {
                maxSide = max(maxSide, (long long)gap);
            }
        }
    }
    if (maxSide == -1)
        return -1;

    return (maxSide * maxSide) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> hf = {2, 3};
    vector<int> vf = {2};

    cout << maximizeSquareArea(4, 3, hf, vf) << endl;

    return 0;
}