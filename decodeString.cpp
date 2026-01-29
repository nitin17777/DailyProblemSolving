#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    // Repeat the enclosed letter 'n' number of times

    stack<pair<string, int>> st;

    string curr = "";

    int num = 0;

    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        else if (c == '[')
        {
            st.push({curr, num});

            curr = "";
            num = 0;
        }

        else if (c == ']')
        {
            auto [prev, k] = st.top();
            st.pop();
            string temp = "";
            while (k--)
            {
                temp += curr;
            }
            curr = prev + temp;
        }

        else
        {
            curr += c;
        }
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "3[a2[c]]";
    cout << decodeString(s) << endl;
}