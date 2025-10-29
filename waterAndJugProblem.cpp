#include <bits/stdc++.h>
using namespace std;

bool canMeasureWater(int x, int y, int target)
{
    // we have two jugs with capacity x and y

    // return whether both jugs may reach target using : 1-> Fill either jug completely with water

    // 2->completely empty other jug

    // pour water from one jug to another until receiving jug is full

    // Approach: Whenever we are pouring water we are actually doing it by a combination of x and y: z = ax + by

    // We have a result called Bezout Identity, which states: for any two integers x and y, all integer combos  ax + by are multiples of gcd(x,y)

    if ((x + y >= target) && (target % __gcd(x, y) == 0))
        return true;
    else
        return false;
}

int main()
{
    cout << (canMeasureWater(3, 5, 4) ? "true" : "false") << endl;
    return 0;
}
