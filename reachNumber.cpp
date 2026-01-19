#include <bits/stdc++.h>
using namespace std;

int reachNumber(int target)
{
    /*
    In each move we can either go right or left



    Return the min number of moves to reach the destination

    */

    // Didn't understood this question much actually

    target = abs(target);
    long long sum = 0;
    int k = 0;

    while (sum < target || (sum - target) % 2 != 0)
    {
        k++;
        sum += k;
    }

    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << reachNumber(2) << endl;

    return 0;
}