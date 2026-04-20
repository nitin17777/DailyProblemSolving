#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPal(string&s)
{
    int i = 0,j= s.size()-1;

    while(i<j)
    {
        if(s[i] != s[j])return false;

        i++;
        j--;
    }
    return true;
}

bool valid(string s)
{
    set<char>st = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

    for(auto &x:s)
    {
        if(st.find(x) == st.end())return false;
    }
    return true;
}

bool solve(string&s)
{
    int n = s.size();

    // Determine if the mirror image of given word is same as given image or not
    /*

    so the given word should be a palindroe which consisits of only certain letters which have same mirror image
    
    */
    return valid(s) && isPal(s);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    cout<<(solve(s)?"YES":"NO")<<endl;

    return 0;
}
