#include<bits/stdc++.h>
#define ll long long
using namespace std;


string reverseParentheses(string s)
{
    int n = s.size();
    
    //Reverse strings in each pair of matching paranthese starting from the innermost one

    string curr = "";

    stack<string>st;

    for(char c:s)
    {
        if(c=='(')
        {
            //Saving the string built before this 
            st.push(curr);

            //Starting new string now
            curr = "";
        }
        
        else if(c==')')
        {

            //Reversing the innermost string 
            reverse(curr.begin(),curr.end());
            
            //Restore the string before '('
            curr=st.top()+curr;
            st.pop();
        }

        else curr+=c;
    }
    return curr;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<reverseParentheses("(u(love)i)")<<endl;

    return 0;
}