#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s)
{
    vector<int> last(26, 0); // For storing lat index of each character in string

    vector<bool> seen(26, false); // to keep a track of already checked characters

    stack<char> st; // to maintain lexicographical minimality

    // For recording last occuring index of each character
    for (int i = 0; i < s.size(); i++)
    {
        last[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (seen[c - 'a'])
            continue; // skip if the character is already used

        // When the stack is not empty and the top character is greater than the currrent element
        // And we know top char will appear again lae=ter as well
        while (!st.empty() && st.top() > c && i < last[st.top() - 'a'])
        {
            seen[st.top() - 'a'] = false;
            st.pop();
        }

        // otherwise simply push the element and mark it as visited
        st.push(c);
        seen[c - 'a'] = true;
    }
    string ans;

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

/*
string removeDuplicateLetters(string s)
{
    set<char>num;
    for(auto x: s)num.insert(x);

    string ans;
    for(auto x: num)
    {
        ans+=x;
    }
    return ans;

}*/

int main()
{
    cout << removeDuplicateLetters("cbacdcbc") << endl;

    return 0;
}
