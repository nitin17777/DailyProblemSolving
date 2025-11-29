#include <bits/stdc++.h>
using namespace std;

bool isPos(string s)
{
    int n = s.size();

    vector<int> cnt(26, 0);
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }

    int flag = 0;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 3)
            flag = 1;

        if (cnt[i] == 2 && (s[0] - 'a' != i || s.back() - 'a' != i))
            flag = 1;
    }
    if (flag)
        return true;

    else
        return false;
}

/*
bool isPos(string s)
{
    /*
    Concatenation of strings a,b and c = s


   int n = s.size();

   char fs = s[0],ls = s[n-1];

   for(int i = 1; i<n-1; i++)
   {
        if((s[i] == fs) || (s[i] == ls))return true;
   }
   return false;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;

        cout << (isPos(s) ? "Yes" : "No") << endl;
    }
    return 0;
}