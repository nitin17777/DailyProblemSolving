#include <bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    // a row i is waker than row j if : 1-> no. of soldiers in i is less than no. of soldiers in row j

    // 2 -> Both rows have same number of soldiers and i < j

    // return the indices of weak rows in matrix ordered from weakest to strongest

    int rows = mat.size();
    int cols = mat[0].size();

    // make the count list of every row with no. of soldiers.
    // Then push the row indices as per the number of soldiers in each row

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < rows; i++)
    {
        int solCount = 0;

        for (int j = 0; j < cols; j++)
        {
            solCount += mat[i][j];
        }
        pq.push({solCount, i});
    }

    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix =
        {{1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0},
         {1, 0, 0, 0, 0},
         {1, 1, 0, 0, 0},
         {1, 1, 1, 1, 1}};

    vector<int> ans = kWeakestRows(matrix, 3);

    for (auto &an : ans)
    {
        cout << an << " ";
    }

    cout << endl;

    return 0;
}