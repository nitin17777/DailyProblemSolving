#include <iostream>
using namespace std;

int main()
{
    int m, n;

    // Input rows and columns
    cin >> m;
    cin >> n;

    int arr[m][n];

    // Input matrix elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Swapping columns
    for (int j = 0; j < n / 2; j++)
    {
        for (int i = 0; i < m; i++)
        {
            swap(arr[i][j], arr[i][n - 1 - j]);
        }
    }

    // Display updated matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
