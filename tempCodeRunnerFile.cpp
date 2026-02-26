#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    string s;
    getline(cin,s);

    int n = s.size();

    // last letter vowel -> Yes else no
    s[n-2] = tolower((unsigned char)s[n-2]);

    set<char>vowels = {'a','e','i','o','u'};

    if(vowels.find(s[n-2]) != vowels.end())cout<<"Yes"<<endl;

    else cout<<"No"<<endl;

    return 0;
}