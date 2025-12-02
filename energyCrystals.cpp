#include <bits/stdc++.h>
using namespace std;

int minNum(int x)
{

    /*
    Energy level of ith crystal is ai
    Initially all are discharged => Energy level = 0
    Each crystal need to be charged to level x


    Min number of actions required to change all the crystals

    for each pair of crystals i,j must hold : ai > aj /2 => Energy level of crystal i must be half of energy level of crystal at j


    */

    int ans = 0;
    int a1 = 0, a2 = 0, a3 = 0;

    while (min({a1, a2, a3}) < x)
    {
        if (a1 <= a2 && a1 <= a3)
        {
            a1 = min(a2, a3) * 2 + 1;
        }
        else if (a2 <= a1 && a2 <= a3)
        {
            a2 = min(a1, a3) * 2 + 1;
        }
        else
        {
            a3 = min(a1, a2) * 2 + 1;
        }
        ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << minNum(n) << endl;
    }
    return 0;
}