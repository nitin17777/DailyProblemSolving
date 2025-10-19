#include <bits/stdc++.h>
using namespace std;

string addOperation(string s, int a)
{
    for (int i = 1; i < s.size(); i += 2)
    {
        s[i] = ((s[i] - '0' + a) % 10) + '0';
    }
    return s;
}

string rotateOperation(string s, int b)
{
    int n = s.size();
    b %= n; // To handle case when b>=n, to wrap it around
    return s.substr(n - b) + s.substr(0, n - b);
}

string findLexSmallestString(string s, int a, int b)
{
    // we can do following 2 operations: Add 'a' to all odd indices of s
    //  Rotate s to right by 'b' positions

    // Return the lexicographically smallest(smaller number) string we can obtain by applying above 2 operations any number of times

    ////////////////////////////////////////////////////////////////////////

    // Approach:
    // Starting with original string ,use a queue to explore transformation

    // for each string do both the operations, and each time push the unseen string into queue

    // And track the lexicographically smallest string seen so far

    // Return the smallest at last

    queue<string> q;
    unordered_set<string> visited;

    string smallest = s;

    q.push(s);
    visited.insert(s);

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        if (curr < smallest)
            smallest = curr;

        // Applying add operation on the current string
        string addStr = addOperation(curr, a);
        if (!visited.count(addStr))
        {
            visited.insert(addStr);
            q.push(addStr);
        }

        // Applying rotate operation
        string rotStr = rotateOperation(curr, b);
        if (!visited.count(rotStr))
        {
            visited.insert(rotStr);
            q.push(rotStr);
        }
    }
    return smallest;
}

int main()
{
    string s = "5525";
    cout << findLexSmallestString(s, 9, 2) << endl;

    return 0;
}
