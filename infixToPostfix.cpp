#include <bits/stdc++.h>
using namespace std;

// precedence function
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;

    else
        return -1;
}

string infixToPostFix(string s)
{

    stack<char> st;

    string result = "";

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        else if (c == '(')
        {
            st.push(c); // push character to the stack
        }

        else if (c == ')')
        {
            while (!st.empty() && st.top() == '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // and then finally remove '('
        }

        // if we encounter an operator
        else
        {
            while (!st.empty() && prec(st.top()) > prec(c))
            {
                if (c == '^' && st.top() == '^')
                    break;

                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string exp = "A+B(C^D-E)^(F+G*H)-I";

    cout << infixToPostFix(exp) << endl;

    return 0;
}