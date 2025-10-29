#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        vector<int> side(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> side[i];
        }

        set<int> freq(side.begin(), side.end());

        if (freq.size() == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
