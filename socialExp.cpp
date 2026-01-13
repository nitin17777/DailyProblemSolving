#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{

    /*
    Teams are req to be formed of 2-3 people
    After which team chooses one of the two civilisations to participate in the exp


    */

    if (n == 2)
        return 2;
    if (n == 3)
        return 3;

    if (n >= 4)
    {
        if (n % 2 == 0)
            return 0;

        else
            return 1;
    }
    return 0;
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

        cout << solve(n) << endl;
    }
    return 0;
}