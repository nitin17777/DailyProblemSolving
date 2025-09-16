#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

string removeDuplicates(string s)
{
    stack<char>st;

    for(char ch :s)
    {
        if(!st.empty() && st.top() ==ch)
        {
            st.pop();
        }

        else
        st.push(ch);
    }

    string result = "";
    while(!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;

}

int main()
{

    string s = "abbaca";
    string ans = removeDuplicates(s);

    cout<<ans<<endl;

    return 0;
}




class Solution {
public:
    string removeDuplicates(string s) {

        stack<char>st;

        for(char ch : s)
        {
            if(!st.empty() && st.top() == ch)
            {
                st.pop();
            }
            else
            st.push(ch);
        }


        string result = "";

        while(!st.empty())
        {
            result = st.top()+result;
            st.pop();

        }
        return result;

    }
};