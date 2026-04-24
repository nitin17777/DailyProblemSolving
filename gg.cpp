#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Node {
    vector<pair<int, int>> path;
    vector<vector<int>> reducedMatrix;
    int cost;
    int vertex;
    int level;
};

// Function to reduce the matrix and return the reduction cost
int reduceMatrix(vector<vector<int>>& matrix, int N) {
    int reductionCost = 0;

    // Row Reduction
    for (int i = 0; i < N; i++) {
        int minVal = INF;
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < minVal) minVal = matrix[i][j];
        }
        if (minVal != INF && minVal != 0) {
            reductionCost += minVal;
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] != INF) matrix[i][j] -= minVal;
            }
        }
    }

    // Column Reduction
    for (int j = 0; j < N; j++) {
        int minVal = INF;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] < minVal) minVal = matrix[i][j];
        }
        if (minVal != INF && minVal != 0) {
            reductionCost += minVal;
            for (int i = 0; i < N; i++) {
                if (matrix[i][j] != INF) matrix[i][j] -= minVal;
            }
        }
    }
    return reductionCost;
}

int minCost = INF;
vector<int> bestPath;

void solveTSP(int N, vector<vector<int>> matrix, int currentCost, int level, int currentVertex, vector<int> path, vector<bool>& visited) {
    if (level == N) {
        // Return to warehouse (node 0)
        if (matrix[currentVertex][0] != INF) {
            int finalCost = currentCost + matrix[currentVertex][0];
            if (finalCost < minCost) {
                minCost = finalCost;
                bestPath = path;
                bestPath.push_back(0);
            }
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && matrix[currentVertex][i] != INF) {
            int tempCost = currentCost + matrix[currentVertex][i];
            
            // Pruning: Branch and Bound check
            if (tempCost < minCost) {
                visited[i] = true;
                path.push_back(i);
                solveTSP(N, matrix, tempCost, level + 1, i, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter number of locations: ";
    if (!(cin >> N)) return 0;

    vector<vector<int>> matrix(N, vector<int>(N));
    cout << "Enter cost matrix (use -1 for INF):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            matrix[i][j] = (val == -1) ? INF : val;
        }
    }

    vector<int> path;
    path.push_back(0);
    vector<bool> visited(N, false);
    visited[0] = true;

    solveTSP(N, matrix, 0, 1, 0, path, visited);

    if (minCost == INF) {
        cout << "No valid path found!" << endl;
    } else {
        cout << "Minimum cost: " << minCost << endl;
        cout << "Path: ";
        for (int i = 0; i < bestPath.size(); i++) {
            cout << bestPath[i] << (i == bestPath.size() - 1 ? "" : "-");
        }
        cout << endl;
    }

    return 0;
}