#include<bits/stdc++.h>
#define ll long long
using namespace std;

int countSubstrings(string s)
{
    int n = s.size();
    int count = 0;

    //We have to return the number of palindromic suubstrings present

    for(int i = 0;i<n;i++)
    {
        //Odd length palindromes
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }

        //Even length palindromes
        l = i;
        r = i+1;

        //Expanding outward while the characters match
        while(l >=0 && r <n && s[l] == s[r])
        {
            count++;
            r++;
            l--;
        }
    }
    return count;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    countSubstring("abc")<<endl;

    return 0;
}




