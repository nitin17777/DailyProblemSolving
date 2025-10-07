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
}

int main()
{
    cout << minSteps(1, 2) << endl;

    return 0;
}
