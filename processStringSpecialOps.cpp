#include<bits/stdc++.h>
#define ll long long
using namespace std;

string reverse(const string& s)
{
    if(s.empty())return "";
    string res ="";

    for(int i=s.size()-1;i>=0;i--)
    {
        res+=s[i];
    }
    return res;
}

string processStr(string s)
{

    string res = "";
    for(auto& x:s)
    {
        if(x=='*')
        {
            if(!res.empty())res.pop_back();
        }

        else if(x=='#')res += res;

        else if(x=='%')
        {
            res = reverse(res);
        }

        else res+=x;
    }

    return res;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<processStr( "a#b%*")<<endl;


    return 0;
}