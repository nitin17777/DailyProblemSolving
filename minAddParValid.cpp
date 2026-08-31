#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minAddToMakeValid(string s)
{
    int n = s.size();

    // Return the min number of moves to make string valid

    stack<char>st;
    for(auto & curr:s)
    {
        if(curr=='(')st.push(curr);

        else 
        {
            if(!st.empty() && st.top() == '(')st.pop();
            else st.push(curr);
        }
    }
    return st.size();
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minAddToMakeValid( "(((")<<endl;

    return 0;
}