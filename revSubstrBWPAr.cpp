#include<bits/stdc++.h>
#define ll long long
using namespace std;


string reverseParentheses(string s)
{
    int n = s.size();
    
    //Reverse strings in each pair of matching paranthese starting from the innermost one

    string ans = "";

    stack<char>st;

    for(auto&x:s)st.insert(x);


    while(!st.empty())
    {
        int curr = st.top();
        st.pop();

        if(curr = ')')
        

    }
    




}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}