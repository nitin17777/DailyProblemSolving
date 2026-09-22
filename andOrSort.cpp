#include <bits/stdc++.h>
using namespace std;

int solve(string& s)
{
    int n = s.size();
    if (s[0] == '1')return count(s.begin(), s.end(), '0');
    
    size_t pos = s.find('1');
    if (pos == string::npos) return 0;

    int f = (int)pos + 1;  // 1-indexed position of first 1


    int totalZeros = count(s.begin(), s.end(), '0');

    int best = INT_MAX;

    int ones = 0, zerosPrefix = 0;

    for (int k = 1; k <= n; k++)
    {
        if (s[k - 1] == '1') ones++;

        else zerosPrefix++;

        if (k >= f - 1)best = min(best, ones + (totalZeros - zerosPrefix));
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}