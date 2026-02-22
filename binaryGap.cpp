#include <bits/stdc++.h>
using namespace std;

int binaryGap(int n)
{
    // Return the longest distance bw 2 adjacent 1s

    string s = bitset<32>(n).to_string();
    int m = s.size();
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        if (s[i] == '1')
        {
            for (int j = i + 1; j < m; j++)
            {
                if (s[j] == '1')
                {
                    ans = max(ans, j - i);
                    break;
                }
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << binaryGap(22) << endl;

    return 0;
}