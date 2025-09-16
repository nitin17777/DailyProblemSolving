#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

string removeDuplicateLetters(string s)
{
    //remove evry dup and sort at last before returning
    unordered_map<char,int>freq;
    string ans = "";
    for(int i = 0;i<s.size();i++)
    {
        if(freq[s[i]] < 1)
        {
            ans+=s[i];
            freq[s[i]]++;
        }
    }
    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    string s = "cbacdcbc";

    string ans = removeDuplicateLetters(s);

    cout<<ans<<endl;

    return 0;
    
}

abcd
acbd