#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a)
{
    int n = a.size();

    /*

    Stalin Sort -> Deleting incorrect greater element directly instead of fixing

    Vulnerable if we can make this array non increasing by repeatedly doing this sort

    Return the number of integers to be removed from array to make it vulnerable
    */

    // Stalin sort can never the first element and the max element

    // We need to remove min elements such that in remaining array : First element is the largest in subsequence

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] <= a[i])
                curr++;
        }
        best = max(best, curr); // max size of array which is acceptable
    }
    return n - best; // and getting the number of elements to be deleted
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