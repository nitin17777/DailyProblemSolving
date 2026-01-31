#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    sort(letters.begin(), letters.end());
    for (auto &c : letters)
    {
        if (c > target)
            return c;
    }
    return letters[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> letters = {'c', 'f', 'j'};
    cout << nextGreatestLetter(letters, 'a') << endl;
    return 0;
}