#include<bits/stdc++.h>
#define ll long long
using namespace std;

string smallestSubsequence(string s)
{
    int n = s.size();
    //lexico. smallest sub with all distinct letters

    vector<int>cnt(26,0);
    vector<bool>vis(26,false);

    for(char c:s)cnt[c-'a']++;

    string st;

    for(char c:s)
    {
        cnt[c-'a']--;

        if(vis[c-'a'])continue;

        while(!st.empty() && st.back()>c && cnt[st.back() - 'a'] > 0)
        {
            vis[st.back() - 'a'] = false;
            st.pop_back();
        }
        st.push_back(c);
        vis[c-'a']= true;
    }
    return st;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<smallestSubsequence("bcabc")<<endl;

    return 0;
}