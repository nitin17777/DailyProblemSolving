#include <bits/stdc++.h>
using namespace std;

string solve(string s)
{
    // chooose two indices i and j,and set si :=sj

    // Replace least occuring character with the most occuring one, do everything lexicographically and return the string
    int n = s.size();

    unordered_map<char, int> freq;
    for (auto x : s)
        freq[x]++;

    priority_queue<pair<int, char>> pq;

    for (auto &p : freq)
    {
        pq.push({p.second, p.first});
    }

    char maxNum = pq.top().second;
    pq.pop();

    char minNum = pq.top().second;
    int minFreq = pq.top().first;

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        if (curr.first < minFreq || (curr.first == minFreq && curr.second < minNum))
        {
            minFreq = curr.first;
            minNum = curr.second;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == minNum)
        {
            s[i] = maxNum;
            break;
        }
    }
    return s;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;

        string s;
        cin >> n >> s;

        cout << solve(s) << endl;
    }
    return 0;
}
