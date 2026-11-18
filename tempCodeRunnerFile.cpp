#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minChanges(string s)
{
    int n = s.size();

    //Beautiful string if we can partition it into one or more substrings such that : Each susbtring has even length and each substring contains only 0s and 1s


    //Determine min changes required to make string 

    int ans = 0;

    for(int i = 0;i<n;i+=2)
    {
        if(s[i] !+ s[i+1])ans++;
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout<<minChanges("1001")<<endl;

    return 0;
}