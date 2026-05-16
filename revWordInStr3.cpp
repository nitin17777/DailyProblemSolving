#include<bits/stdc++.h>
#define ll long long
using namespace std;

string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<reverseWords("Let's take LeetCode contest")<<endl;


    return 0;
}