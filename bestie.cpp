#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();

    /*
    We are asked to make gcd of all numbers in array equal to 1

    In one move: We can make ai = gcd(ai,i) and cost = n-i+1

    Find the min total cost of operation we need to perform so that GCD of all elements in the given array = 1

    */
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