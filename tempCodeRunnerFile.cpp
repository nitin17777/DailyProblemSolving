#include<bits/stdc++.h>
using namespace std;

bool hasDigit(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(isalnum(s[i]))return true;
    }
    return false;
}

bool both(string s)
{
    bool hasUpper = false, hasLower = false;

    for (char c : s) 
    {
        if (c >= 'A' && c <= 'Z') hasUpper = true;
        if (c >= 'a' && c <= 'z') hasLower = true;
    }

    return hasUpper && hasLower;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string s;
    cin>>s;

    if((s.size() >= 5) && (hasDigit(s)) && both(s))
    {
        cout<<"Correct"<<endl;
    }

    else cout<<"Too weak"<<endl;
    
    return 0;
}