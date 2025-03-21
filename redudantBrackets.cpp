#include<iostream>
#include<stack>
using namespace std;

//we have to remove all those brackets which are of no use

bool findRedBrac kets(string& s)
{
    stack<char>st;

    for(int i = 0;i<s.length();i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        {
            st.push(ch);

        }
        else
        {
            //ch ya toh ')' ya lowercase letter

            if(ch == ')')
            {
                bool isRedundant = true;

                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
 
                }
                if(isRedundant == true)
                {
                    return true;
                    st.pop();
                }

            }
        }
    }
    return false;

}


int main()
{

    string exp ="((a+b))";

    if(findRedBrackets(exp))
    {
        cout << "The expression contains redundant brackets." << endl;
    }
    else
    {
        cout << "The expression does not contain redundant brackets." << endl;
    }
    return 0;

}