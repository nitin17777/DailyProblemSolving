#include<bits/stdc++.h>
#define ll long long
using namespace std;

int numberOfSubstrings(string s)
{
    int n = s.size();

    vector<int>cnt(3);

    int l = 0;
    int ans = 0;

    for(int r = 0;r<n;r++)
    {
        cnt[s[r]-'a']++;

        while(cnt[0] && cnt[1] && cnt[2])
        {
            ans+=n-r;
            
            cnt[s[l]-'a']--;
            l++;
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfSubstrings("abcabc")<<'\n';
    return 0;
}