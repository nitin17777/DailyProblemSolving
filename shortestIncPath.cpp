#include <iostream>
#include <vector>
using namespace std;

int minSteps(int x, int y)
{

    // odd steps-> x axis =>sum of odd index steps = x coordinate
    // even steps-> y axis =>sum of even index steps = y coordinate

    // each step must have length strictly greater than the length of previous one

    // return the min number of steps needed to reach (x,y) else return -1

    // if y>x -> 3 steps

    if (x == y || x == y + 1 || y == 1)
        return -1;

    else if (x < y)
        return 2;

    else
        return 3;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        cout << minSteps(x, y) << endl;
    }

    return 0;
}
