#include <iostream>
#include <vector>
using namespace std;

class LibrarySearch {
private:
    vector<int> bookIDs;
    int n;

public:
    void inputBookIDs(int size) {
        n = size;
        bookIDs.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> bookIDs[i];
        }
    }

    bool binarySearch(int target) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (bookIDs[mid] == target) {
                return true;
            } else if (bookIDs[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    int n, target;
    cout << "Enter number of books: ";
    cin >> n;

    LibrarySearch obj;
    cout << "Enter " << n << " sorted book IDs: ";
    obj.inputBookIDs(n);

    cout << "Enter book ID to search: ";
    cin >> target;

    if (obj.binarySearch(target)) {
        cout << "Book Found" << endl;
    } else {
        cout << "Book Not Found" << endl;
    }

    return 0;
}