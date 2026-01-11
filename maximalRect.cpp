#include <bits/stdc++.h>
using namespace std;

int largestRectArea(vector<int> &heights)
{
    stack<int> st; // To store indices of histgram bars
    int maxArea = 0;

    heights.push_back(0);

    for (int i = 0; i < heights.size(); i++)
    {
        /*
        If current basr is smaller than bar at stack top -> rectangle with height = heights[st.top()] must end here
        */

        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int h = heights[st.top()];
            st.pop();

            int w = st.empty() ? i : i - st.top() - 1;

            maxArea = max(maxArea, w * h);
        }
        st.push(i);
    }
    heights.pop_back();
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> height(cols, 0); // to store histogram heights for each column

    int ans = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                height[j] += 1;

            else
                matrix[j] = 0; // else we wil reset
        }

        ans = max(ans, largestRectArea(height));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<char>> m = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(m) << endl;
    return 0;
}