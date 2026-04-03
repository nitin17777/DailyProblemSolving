#include<bits/stdc++.h>
using namespace std;

string breakPalindrome(string s)
{
    int n = s.size();

    if(n == 1)return "";


    /*

    Replace exactly one char wirh letter such that resulting string is not not palindrome and lexicog. the smallest

    
    */

     //Checking till half because to change the palindrome , the only change is needed in one half
    for(int i = 0;i<n/2;i++)
    {
        //Return the changed string as soon as any non 'a' character is found
        if(s[i] != 'a')
        {
            s[i] = 'a';
            return s;
        } 
    }


    s[n-1] = 'b';
    return s;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<breakPalindrome("abccba")<<endl;

    
    return 0;
}