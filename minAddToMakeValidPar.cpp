#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minAddToMakeValid(string s)
{
    int n=s.size();

    stack<char>st;

    for(auto &x:s)
    {

        if(x=='(')st.push(x);

        else
        {
            if(!st.empty() && st.top() == '(')st.pop();

            else st.push(x);
        }
    }
    return st.size();
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minAddToMakeValid("())")<<endl;

    return 0;
}