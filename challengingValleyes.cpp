#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a)
{

    int n = a.size();

    /*

    Valley If:

    Check for a number :

                        Greater number before it's first element
                        Greater number after it's last element
                        All number equal after it's first element



    Determine whether the given array is valley or not
    */

    // just check if right and left any number is greater than number

    // But the problem is : What if the number has it's own separate stack and it's first and last digit follow the required conditions??

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || a[i - 1] > a[i]) && (i == n - 1 || a[i] < a[i + 1]))
            cnt++;
    }
    if (cnt == 1)
        return true;

    return false;
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

        vector<int> a;

        // Removing the duplciates already during the input
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (i == 0 || x != a.back())
            {
                a.push_back(x);
            }
        }

        cout << (solve(a) ? "Yes" : "No") << endl;
    }
    return 0;
}