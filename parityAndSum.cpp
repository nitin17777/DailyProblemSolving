#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int> &a)
{
    // Pick two different parity nums and replace the smaller one with their sum

    // Return the min ops required to make all the elements of the array have same parity

    // sum of opposite parities =  an odd number

    // if greatest number is odd -> number of evens is answer

    // if even number is greatest
    sort(a.begin(), a.end());
    vector<int> even, odd;

    for (auto &x : a)
    {
        if (x % 2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
    }

    // Case when largest number is odd -> Simply number of evens is the answer
    int en = even.size(), on = odd.size();
    int cnt = 0;

    if (en == 0 || on == 0)
        return 0;

    ll maxOdd = odd.back();

    int l = 0, r = en - 1;

    while (l <= r)
    {
        if (even[l] < maxOdd)
        {
            // Processing smallest even first
            maxOdd += even[l++];
            cnt++;
        }
        else
        {
            // Spend on largest even to maxismise M growth
            maxOdd += 2LL * even[r--];
            cnt += 2;
        }
    }
    return cnt;
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

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}