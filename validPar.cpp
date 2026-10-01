#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool matches(char s,char e)
{
    
    return(s == '{' && e == '}' ) ||

    (s == '[' && e == ']') ||
    (s == '(' && e == ')');
}

bool isValid(string s)
{
    int n = s.size();
    
    stack<char>st;

    for(auto &x:s)
    {
        if(x=='(' || x=='{' || x == '[')st.push(x);

        else
        {
            if(st.empty())return false;

            char top = st.top();
            
            if(matches(top,x))st.pop();
            else return false;
        }
    }

    return st.empty();

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<isValid("(]")<<endl;

    return 0;
}