#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isSubsequence(string s, string t)
{
    int n = s.size(),m = t.size();

    int curr = 0 ;

    for(int i=0;i<m;i++)
    {
        if(t[i] == s[curr])curr++;
    }

    return curr == n;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout<<(isSubsequence("abc","ahbgdc")?"True":"False")<<endl;

    return 0;
}