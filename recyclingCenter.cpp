#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Very good question and very good solution actually
int minCoins(vector<int> &weights, int limit)
{
    // choose any element and make it 0  and cost increments by 1

    // if ai(choosen element) > c => cost = 1 Coins otherwise 0 coins

    // and after this, weight of every remaining bag will get doubled

    // min cost to turn all elements of array 0

    /*LOGIC:

    //sort in descending order first, then check if it's weight * no. of times we have saved an element <= c,if yes,increase saved

    //at last return total elements - no. of saved = no. of unsaved

    */

    int n = weights.size();

    sort(weights.begin(), weights.end(), greater<int>());
    // 1,4,8,10,15

    // 10,15,8,4,1

    int saved = 0;
    for (ll weight : weights)
    {
        if (weight * (1LL << saved) <= limit)
        {
            saved++;
        }
    }
    return n - saved;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> weights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> weights[i];
        }

        cout << minCoins(weights, c) << endl;
    }
    return 0;
}
