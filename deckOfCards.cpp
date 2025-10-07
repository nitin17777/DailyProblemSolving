#include <bits/stdc++.h>
using namespace std;

// Function to determine the fate of cards
string findCardFate(int n, int k, const string &s)
{
    int min_top = 0, max_top = 0;
    int min_bottom = 0, max_bottom = 0;

    // Count top/bottom removals
    for (char c : s)
    {
        if (c == '0')
        {
            min_top++;
            max_top++;
        }
        else if (c == '1')
        {
            min_bottom++;
            max_bottom++;
        }
        else
        { // '2'
            max_top++;
            max_bottom++;
        }
    }

    string result(n, '?');

    // Definitely removed from top
    for (int i = 0; i < min_top; i++)
        result[i] = '-';

    // Definitely removed from bottom
    for (int i = 0; i < min_bottom; i++)
        result[n - 1 - i] = '-';

    // Definitely safe (remaining cards)
    for (int i = max_top; i < n - max_bottom; i++)
        result[i] = '+';

    return result;
}

// ---------------------- MAIN FUNCTION ----------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;

        cout << findCardFate(n, k, s) << endl;
    }
    return 0;
}
