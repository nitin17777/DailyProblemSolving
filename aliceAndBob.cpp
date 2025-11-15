#include <bits/stdc++.h>
using namespace std;

int ans(vector<int> &marbles, int a)
{
    int n = marbles.size();
    /*
    Bob wins if |v-b| < |v-a|

    //just fit the given a in given array, now compare the size of right and left array to it. if left array's size is greater , return a - 1
    /else return a+1


    */

    int left = lower_bound(marbles.begin(), marbles.end(), a) - marbles.begin();

    // Step 3: count values > a
    int right = marbles.end() - upper_bound(marbles.begin(), marbles.end(), a);

    if (left > right)
        return a - 1;
    else
        return a + 1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a;
        cin >> n >> a;

        vector<int> marbles(n);
        for (auto &x : marbles)
            cin >> x;

        cout << ans(marbles, a) << endl;
    }
    return 0;
}
