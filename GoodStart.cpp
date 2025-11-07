#include <iostream>
using namespace std;

bool canTile(long long w, long long h, long long a, long long b, long long x1, long long y1, long long x2, long long y2)
{
    // We need to cover the roof with tiles of size a*b : Sheets can't be rotated + they must not overlap + These sheets can extend beyond thhe boundaries of the recatngualar roof

    // Determine if it is possible to completely tile the roof without removing either of the two already placed sheets
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long w, h, a, b;

        long long x1, y1, x2, y2;
        cin >> w >> h >> a >> b;
        cin >> x1 >> y1 >> x2 >> y2;

        if (canTile(w, h, a, b, x1, y1, x2, y2))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}