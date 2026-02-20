#include <bits/stdc++.h>
using namespace std;

string makeLargestSpecial(string s)
{
    int n = s.size();

    /*Special binary string's property :
    Same number of zeroes and ones


    In one move, we can choose two consecutive non empty special substrings of s and swap them

    Return the lexicographically largest resuting string possible after applying the mentioned operations


    */

    vector<string> blocks;

    int balance = 0; // Balancing like parentheses
    int start = 0;   // Starting index of current block

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            balance++; // Increasing balance for 1 and decreasing for 0

        else
            balance--;

        // When balance becomes 0 -> We found a smallest valid special substring from index start to i

        if (balance == 0)
        {
            /*

            Structure of special substring: 1 + (inner special string) + 0, so we are recurisely solving the inner part

            */
            string inner = s.substr(start + 1, i - start - 1);

            // recursively maximise the inner string
            string optInner = makeLargestSpecial(inner);

            // Rebuild the block with optimised inner
            string block = "1" + optInner + "0";

            blocks.push_back(block);

            start = i + 1;
        }
    }

    // sorting to get the lexicographically largest string
    sort(blocks.rbegin(), blocks.rend());

    // Concatenating  sorted blocks
    string result = "";

    for (string &block : blocks)
        result += block;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << makeLargestSpecial("11011000") << endl;

    return 0;
}