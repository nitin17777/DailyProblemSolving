#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int a, int b)
{
    // greedy path: if it starts with top left cell and moevs  right or downward and always to neighbour with greater value
    // value of path is sum of the values of cells it  visits including start and ending one

    // is this type of path possible

    if ((a == 1 || b == 1) || (a == 2 && b == 2))
        return false;
    else
        return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << (isPossible(a, b) ? "YES" : "NO") << endl;
    }

    return 0;
}
