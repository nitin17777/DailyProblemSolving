#include <bits/stdc++.h>
using namespace std;

int countVowels(string &s)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, s3;

    // Read full lines (including spaces)
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    if (countVowels(s1) == 5 && countVowels(s2) == 7 && countVowels(s3) == 5)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    // set<char>vowels = {'a','e','i','o','u'};

    // vector<string>s(3);

    // for(auto &x: s)cin>>x;

    // string s1 = s[0];

    // int cnt1= 0;
    // for(auto & x :s1)
    // {
    //     if(vowels.find(x) != vowels.end())cnt1++;
    // }
    // if(cnt1 != 5)
    // {
    //     cout<<"No"<<endl;
    //     continue;
    // }

    // string s2 = s[1];
    // int cnt2= 0;
    // for(auto & x :s2)
    // {
    //     if(vowels.find(x) != vowels.end())cnt2++;
    // }
    // if(cnt2 != 7)
    // {
    //     cout<<"No"<<endl;
    //     continue;
    // }

    // string s3 = s[2];
    // int cnt3= 0;
    // for(auto & x :s3)
    // {
    //     if(vowels.find(x) != vowels.end())cnt3++;
    // }
    // if(cnt3 != 5)
    // {
    //     cout<<"No"<<endl;
    //     continue;
    // }

    // cout<<"Yes"<<endl;

    return 0;
}