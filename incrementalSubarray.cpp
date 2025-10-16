#include <bits/stdc++.h>
using namespace std;

/**
 * Counts how many times the favorite pattern appears in James' array
 *
 * @param n - Maximum number James writes (array b goes up to n)
 * @param m - Length of the favorite numbers array
 * @param favoriteNumbers - The pattern we're searching for
 * @return Number of occurrences of the pattern in array b
 */
int countPatternOccurrences(int n, int m, vector<int> &favoriteNumbers)
{
    // Key insight: The array b is structured as:
    // [1], [1,2], [1,2,3], ..., [1,2,3,...,n]

    // The favorite pattern can appear in any "row" that is long enough
    // A row i contains numbers [1, 2, 3, ..., i]

    int lastNumber = favoriteNumbers[m - 1];

    // Base answer: number of rows that contain all numbers up to lastNumber
    // Rows lastNumber, lastNumber+1, ..., n all contain the pattern
    int answer = n - lastNumber + 1;

    // Special case: If any number (except the first) in favoriteNumbers is 1,
    // it means the pattern "wraps around" between rows
    // Example: [3, 4, 1] spans across row boundaries
    // In this case, there's only 1 occurrence
    for (int i = 1; i < m; i++)
    {
        if (favoriteNumbers[i] == 1)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> favoriteNumbers(m);
        for (int i = 0; i < m; i++)
        {
            cin >> favoriteNumbers[i];
        }
        int result = countPatternOccurrences(n, m, favoriteNumbers);
        cout << result << "\n";
    }

    return 0;
}