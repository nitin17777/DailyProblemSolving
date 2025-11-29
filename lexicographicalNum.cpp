#include <bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n)
{

    // we have to return all numbers in range [1,n] sorted in lexicographical order

    vector < int> ans;
    ans.reserve(n);

    int curr = 1;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(curr);

        // Trying to go deeper
        if (curr * 10 <= n)
            curr *= 10;

        else
        {
            // moving to next while avoiding overflow or trailing 9
            while (curr % 10 == 9 || curr + 1 > n)
            {
                curr /= 10;
            }
            curr++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ans = lexicalOrder(13);
    for (auto &a : ans)
        cout << a << " ";

    cout << endl;

    return 0;
}