#include <bits/stdc++.h>
using namespace std;
#define ll long long

int minOps(int n)
{
    vector<int> a(n, 0);

    /*we can perform two ops: choose index i such tha ai = 0 and assign 1 to ai

    choose l and r such that  1 <= l <= r <= n , al = 1 and ar =1

    al+ ... + ar >= (r-l+1) /2 and assign 1 to ai for all l<=i<=r

    Return min ops of first type required to make all elements of array equal to 1

    */

    ll ones = 1;
    int op1 = 1;

    while (ones < n)
    {
        ones = 2 * (ones + 1);
        op1++;
    }
    return op1;
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

        cout << minOps(n) << endl;
    }
    return 0;
}