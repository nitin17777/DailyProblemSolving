#include <iostream>
using namespace std;

int main()
{
    int row, col;

    // Input dimensions of the 2D array
    cin >> row >> col;

    // Dynamically allocate memory for a 2D array
    int **arr = new int*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col]; // Fixed to allocate memory for 'col' columns
    }

    // Input elements of the 2D array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    // Output elements of the 2D array
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl; // Move to the next line after printing a row
    }

    // Release dynamically allocated memory
    for (int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
