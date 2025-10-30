#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Trying every possible substring from current index
// if substrins is palindrome => include it and recurse

// backtrack to try every next possibility

void solve(int start, string &s, vector<string> &path, vector<vector<string>> &ans)
{
    // when entire string is covered, push the current partition
    if (start == s.size())
    {
        ans.push_back(path);
        return;
    }

    for (int end = start; end < s.size(); end++)
    {

        if (isPalindrome(s, start, end))
        {
            path.push_back(s.substr(start, end - start + 1)); // substr(pos, length)

            solve(end + 1, s, path, ans);
            path.pop_back(); // backtrack
        }
    }
}

vector<vector<string>> partition(string s)
{
    // partition s such that every substring of partition is a palindrome

    vector<vector<string>> ans;
    vector<string> path;

    solve(0, s, path, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = partition("aab");

    for (auto &an : ans)
    {
        for (auto a : an)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}
