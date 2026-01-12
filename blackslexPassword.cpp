#include <bits/stdc++.h>
using namespace std;

// Didn;t really understood :)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;

        /*
        if j-i are divisble by x => si , sj are different

        j = i+x; j = i+2x; j = i+3x...


        */

        cout << k * x + 1 << endl;
    }
    return 0;
}