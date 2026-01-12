#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    for (int i = 1; i < n / 2; i++)
    {
        if (i * i == n)
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve(16) << endl;
    return 0;
}