#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a, int s)
{
    int n = a.size();

    // Given array contains atleast one 0,1 and 2

    // She wants the sum to be exactly s
    int bSum = accumulate(a.begin(), a.end(), 0);

    vector<int> ans;

    // Difference bw any two consecutive numbers == 1

    // Determine if ther is anny possible arrangement such taht Alice can't find her target, return the arrangement if it is possible

    // Case 1 : s < baseSum ->No path sum can equal s, so any combo can work here in this case

    // if(s<bSum) -> Soo better to combine it with last case

    // Case 2 : s = baseSum -> return -1 , as it would always be possible to satisfy the condition

    if (s == bSum || s >= bSum + 2)
        return {-1};

    // Case 3 : s > baseSum ->if difference = 1 ->just dont' pair 0 and 1
    //                           diff != 1 - >return -1

    // if(s>bSum)
    // {
    //     //When Alice wants 1 to reach the target sum
    //     if(abs(bSum-s) == 1)
    //     {

    //     }

    //     else return -1;
    // }

    map<int, int> mp;
    for (auto &x : a)
        mp[x]++;

    for (int i = 0; i < mp[0]; i++)
        ans.push_back(0);
    for (int i = 0; i < mp[2]; i++)
        ans.push_back(2);
    for (int i = 0; i < mp[1]; i++)
        ans.push_back(1);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        vector<int> ans = solve(a, s);
        for (auto &x : ans)
            cout << x << " ";

        cout << endl;
    }
    return 0;
}