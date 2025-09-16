#include <iostream>
#include <vector>
using namespace std;

class RollNumberSearch {
private:
    vector<int> rollNumbers;

public:
    void inputRollNumbers(int n) {
        rollNumbers.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> rollNumbers[i];
        }
    }

    int binarySearch(int target) {
        int left = 0, right = rollNumbers.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (rollNumbers[mid] == target) {
                return mid + 1;
            } else if (rollNumbers[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    int n, target;
    cout << "Enter number of students: ";
    cin >> n;

    RollNumberSearch obj;
    cout << "Enter " << n << " sorted roll numbers: ";
    obj.inputRollNumbers(n);

    cout << "Enter roll number to search: ";
    cin >> target;

    int position = obj.binarySearch(target);
    if (position != -1) {
        cout << "Position: " << position << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}