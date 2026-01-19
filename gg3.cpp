#include <bits/stdc++.h>
using namespace std;

// Binary Search to find smallest index of k
int binarySearchFirst(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            ans = mid;      // store index
            high = mid - 1; // search left for smaller index
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter value to search: ";
    cin >> k;

    int result = binarySearchFirst(arr, n, k);

    cout << result << endl;
    return 0;
}
