

#include <iostream>
using namespace std;

/* Swap function */
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* Partition function */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

/* Quick Sort function */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Main function */
int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted list:
        for (auto &x : arr) cout
         << x << "
        cout
         << endl;

    return 0;
}