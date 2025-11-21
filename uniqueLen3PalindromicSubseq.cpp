#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s)
{

    int n = s.size();

    /*Return the numebr of unique palindromes of length 3 that are subsequence of s

    */

    vector<int> first(26, -1), last(26, -1);

    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';

        // if it is the first existence of this char
        if (first[c] == -1)
            first[c] = i;

        last[c] = i; // Also for now mark this as the last occuring position
    }

    int ans = 0;

    for (int c = 0; c < 26; c++)
    {
        int L = first[c], R = last[c];

        if (L == -1 || R - L < 2)
            continue; // NOT much space to insert

        unordered_set<char> mid;

        for (int i = L + 1; i < R; i++)
        {
            mid.insert(s[i]);
        }

        ans += mid.size();
    }
    return ans;
}

int main()
{
    cout << countPalindromicSubsequence("aabca") << endl;
    return 0;
}