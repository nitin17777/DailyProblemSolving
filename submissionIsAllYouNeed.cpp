#include <bits/stdc++.h>
using namespace std;

// Function to compute maximum possible score
long long maxScore(const vector<long long>& S) {
    long long sum = 0; //total sum of elements in S
    long long cnt0 = 0; // to count how many 0 are there

    for (auto x : S) {
        sum += x;//accumulating sum
        if (x == 0) cnt0++;
    }

    //Each zero gives +1 extra over the sum
    return sum + cnt0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin >> n;

    vector<long long> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cout << maxScore(S) << endl;
    }
}
