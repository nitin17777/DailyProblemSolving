#include <iostream>
#include <vector>
using namespace std;

int minTurns(int rows, int cols, int srow, int scol)
{
    // m wants to minimize,but f wants to maximise,,
    // Return
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        cout << minTurns(n, m, a, b);
    }
    return 0;
}
