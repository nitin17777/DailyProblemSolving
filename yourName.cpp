#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        unordered_map<char, int> freqS;
        for (auto an : s)
        {
            freqS[an]++;
        }

        unordered_map<char, int> freqT;
        for (auto an : t)
        {
            freqT[an]++;
        }

        if (freqT == freqS)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
