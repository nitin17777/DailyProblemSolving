#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string n;
        cin >> n;

        vector<int> digits;
        int sum = 0;

        for (char c : n)
        {
            int d = c - '0';
            digits.push_back(d);
            sum += d;
        }

        if (sum <= 9)
        {
            cout << 0 << "\n";
            continue;
        }

        sort(digits.begin(), digits.end()); // ascending

        int kept_sum = 0;
        int kept_count = 0;

        for (int d : digits)
        {
            if (kept_sum + d <= 9)
            {
                kept_sum += d;
                kept_count++;
            }
            else
                break;
        }

        cout << digits.size() - kept_count << "\n";
    }

    return 0;
}