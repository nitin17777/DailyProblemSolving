#include <bits/stdc++.h>
using namespace std;

bool can(int a, int b, string s)
{
    int n = s.size();

    int x = 0, y = 0;

    int i = 0;
    int cycle = 0;

    for (int i = 0; i < 100; i++)
    {
        for (char dir : s)
        {

            if (dir == 'N')
                y++;
            if (dir == 'S')
                y--;

            if (dir == 'E')
                x++;
            if (dir == 'W')
                x--;

            if (x == a && y == b)
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b;
        string s;

        cin >> n >> a >> b >> s;

        cout << (can(a, b, s) ? "Yes" : "No") << endl;
    }
    return 0;
}
