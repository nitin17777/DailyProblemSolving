#include <iostream>
#include <vector>
using namespace std;


/*
vector<int> buildPermutation(int n, int x) {
    vector<int> p;

    // Step 1: Add all elements < x
    for (int i = 0; i < x; i++) {
        p.push_back(i);
    }

    // Step 2: Add all elements > x
    for (int i = x + 1; i < n; i++) {
        p.push_back(i);
    }

    // Step 3: Add x at the end
    p.push_back(x);

    return p;
}
    */

int main() {

    int t;
    cin>>t;

    while(t--)
    {

    int n, x;
    cin >> n >> x;

    vector<int> p = buildPermutation(n, x);

    for (int val : p) {
        cout << val << " ";

    }
    cout << endl;

    }
    

    return 0;
}
