#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n][n];

    // Input matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    // Finding sum of elements below diagonal (i > j)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
            {
                sum += arr[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}
