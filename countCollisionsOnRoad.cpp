#include <bits/stdc++.h>
using namespace std;

int countCollisions(string directions)
{

    // two cars moving in opposite directions collide -> +2
    // moving car collide with stationary car -> +1

    // Return totall number of collisions that will happen

    int n = directions.length();

    // RL will contribute 2, XS will contribute 1

    // Removing leading 'L' and trailing 'R' as they won't collide with any
    int left = 0;
    while (left < n && directions[left] == 'L')
        left++;

    int right = n - 1;
    while (right >= 0 && directions[right] == 'R')
        right--;

    int ans = 0;
    for (int i = left; i <= right; i++)
    {
        if (directions[i] == 'L' || directions[i] == 'R')
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << countCollisions("RLRSLL") << endl;

    return 0;
}