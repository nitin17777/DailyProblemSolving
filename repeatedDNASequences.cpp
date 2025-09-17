#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    // return the 10 letter long substring that occurs more than once in
    unordered_set<string> seen, repeated;

    int n = s.size();

    for (int i = 0; i + 10 <= n; i++)
    {
        string sub = s.substr(i, 10);
        if (seen.count(sub))
        {
            repeated.insert(sub);
        }
        else
        {
            seen.insert(sub);
        }
    }
    vector<string> ans;

    for (auto &rep : repeated)
    {
        ans.push_back(rep);
    }

    return ans;
}

int main()
{

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> ans = findRepeatedDnaSequences(s);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}