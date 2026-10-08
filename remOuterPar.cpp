#include<bits/stdc++.h>
#define ll long long
using namespace std;

string removeOuterParentheses(string s)
{
    string ans;
    int balance = 0;

    for (char c : s) {

        if (c == '(') {
            if (balance > 0)
                ans += c;

            balance++;
        }
        else {
            balance--;

            if (balance > 0)
                ans += c;
        }
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<

    return 0;
}