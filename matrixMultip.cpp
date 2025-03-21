#include <iostream>
#include <vector>
using namespace std;

// Function to take matrix input
void inputMatrix(vector<vector<int>>& mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to multiply two matrices
vector<vector<int>> matrix_multiply(const vector<vector<int>>& mat1, int r1, int c1,
                                    const vector<vector<int>>& mat2, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        exit(0);
    }
    
    vector<vector<int>> result(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int r1, c1, r2, c2, r3, c3;
    
    // Input dimensions for A
    cout << "Enter dimensions of Matrix A (rows cols): ";
    cin >> r1 >> c1;
    vector<vector<int>> A(r1, vector<int>(c1));
    cout << "Enter elements of Matrix A: " << endl;
    inputMatrix(A, r1, c1);
    
    // Input dimensions for B
    cout << "Enter dimensions of Matrix B (rows cols): ";
    cin >> r2 >> c2;
    vector<vector<int>> B(r2, vector<int>(c2));
    cout << "Enter elements of Matrix B: " << endl;
    inputMatrix(B, r2, c2);
    
    // Input dimensions for C
    cout << "Enter dimensions of Matrix C (rows cols): ";
    cin >> r3 >> c3;
    vector<vector<int>> C(r3, vector<int>(c3));
    cout << "Enter elements of Matrix C: " << endl;
    inputMatrix(C, r3, c3);
    
    // Check viability of multiplication ABC
    if (c1 != r2 || c2 != r3) {
        cout << "Matrix multiplication ABC is not possible!" << endl;
        return 0;
    }
    
    // Multiply A * B
    vector<vector<int>> AB = matrix_multiply(A, r1, c1, B, r2, c2);
    
    // Multiply (AB) * C
    vector<vector<int>> ABC = matrix_multiply(AB, r1, c2, C, r3, c3);
    
    // Print all matrices
    cout << "\nMatrix A: " << endl;
    printMatrix(A);
    
    cout << "\nMatrix B: " << endl;
    printMatrix(B);
    
    cout << "\nMatrix C: " << endl;
    printMatrix(C);
    
    cout << "\nMatrix ABC: " << endl;
    printMatrix(ABC);
    
    return 0;
}
