#include <bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> &a, vector<int> &q)
{
    /*

    n different questions can be asked in the exam


    ai -> The only question which is not present in the ith list


    He will recieve one of these m lists of questions

    And he will pass only if he knows all the questions from the list


    He knows the answer for k questions : q1, q2,...qk

    ith character should be 1 if he passes the exam if he recieves the ith question list, 0 if won't pass
    */

    int m = a.size();
    int k = q.size();

    string ans = "";

    vector<bool> used(n + 1, false);

    for (int i = 0; i < k; i++)
        used[q[i]] = true; // marking the questions he knows

    for (int i = 0; i < m; i++)
    {
        // Case when he knows all the answer OR when the question he doesn't know is not in the list of qustions asked

        if ((k == n) || ((k == n - 1) && !used[a[i]]))
            ans += '1';

        else
            ans += '0';
    }
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
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m), q(k);

        for (auto &x : a)
            cin >> x;
        for (auto &x : q)
            cin >> x;

        cout << solve(n, a, q) << endl;
    }
    return 0;
}