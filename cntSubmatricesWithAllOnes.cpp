#include <bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};

    cout << numSubmat(mat) << endl;

    return 0;
}