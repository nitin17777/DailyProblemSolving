#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &a)
{
    int n = a.size();

    sort(a.begin(), a.end()); // since he can manipulate the array according to himself and make a pattern which will gaurantee him a win

    /*
    and make an array such that k won't able to stop him from winning:By making a2k and a2k+1 equal
    */
    for (int i = 1; i <= n - 2; i += 2)
    {
        if (a[i] != a[i + 1])
            return false;
    }
    return true;
}

/* Wrong approach
bool isPossible(vector<int> &a)
{
    int n = a.size();

    if (n % 2 == 0)
        return true;

    set<int> freq(a.begin(), a.end());

    // if n is odd and there are more than 2 distinct values → not possible
    return freq.size() <= 2;
}*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        cout << (isPossible(a) ? "Yes" : "No") << endl;
    }
    return 0;
}
