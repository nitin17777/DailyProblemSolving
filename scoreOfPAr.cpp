#include<bits/stdc++.h>
#define ll long long
using namespace std;

int scoreOfParentheses(string s)
{
    //() Score = 1
    //AB has score A+B, A and B are balanced strings
    //(A) has score 2*A, A is balanced string

    stack<int>st;
    st.push(0);

    for(auto &c:s)
    {
        if(c =='(')st.push(0);
       
        else
        {
            int inner = st.top();
            st.pop();

            int score = (inner==0)?1: 2*inner;

            st.top() += score;
        }
    }
    return st.top();
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<scoreOfParentheses("(())")<<endl;

    return 0;
}