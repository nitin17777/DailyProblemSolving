#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    // we have to find whether if the given string s can be written as space separted wordDict words

    // creating an unordered set
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    int n = s.length();

    // creating a dp array of size n+1 , initiallised to false

    // dp[i] will be true if s can broken into words from wordDict
    vector<bool> dp(n + 1, false);

    dp[0] = true; // since an empty string is always segmentable

    // iterating through string s from index 1 to n
    for (int i = 1; i <= n; i++)
    {
        // checking every possible substring ending at index i
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

int main()
{
    string s = "leetcode";

    vector<string> wordDict = {"leet", "code"};

    if (wordBreak(s, wordDict))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}