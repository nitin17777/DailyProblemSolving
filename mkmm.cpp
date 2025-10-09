#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + j];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k++] = left[i++];
        }

        else
        {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {4, 5, 2, 9};
    mergeSort(arr);

    for (auto &an : arr)
    {
        cout << an << " ";
    }
    cout << endl;
}