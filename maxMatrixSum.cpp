#include <bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // we have choice to : Choose any two adjacent elements of matrix and multiply each of them by -1

    // We have to maximise the summation of matrix's elements

    // Return the max sum of matrix's elements using this operation

    int neg = 0, sum = 0;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += abs(matrix[i][j]);
            mini = min(mini, abs(matrix[i][j]));

            if (matrix[i][j] < 0)
                neg++;
        }
    }

    if (neg % 2 != 0)
        return sum - 2 * mini; // if odd return totalSum - min

    else
        return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}};
    cout << maxMatrixSum(matrix) << endl;

    return 0;
}