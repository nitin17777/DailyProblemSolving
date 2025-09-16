#include<iostream>
#include<vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    if(n == 0)return "";


    //dp[i][j] means s[i.....j] is palindrome or not

    vector<vector<bool>>dp(n,vector<bool>(n,false));

    int start = 0; 
    int maxLen = 1;


    //string of length 1 will always be a plaindrome
    for(int i = 0;i<n;i++)
    {
        dp[i][i] = true; // it denotes every single character 
    }

    //checking for string of length 2
    for(int i = 0; i < n ;i++)
    {
        if(s[i] == s[i+1])
        {
            dp[i][i+1] = true; //string form i to i+1 is a palindrome
            start = i;
            maxLen = 2;

        }
    }

    //Checking substring of length >= 3

    for(int len = 3;len<=n;len++)
    {
        for(int i = 0; i<=n-len; i++)
        {
            int  j = i+len-1; //ending index

            if(s[i] == s[j] && dp[i+1][j-1])
            {
                dp[i][j] = true;


                if(len>maxLen)
                {
                    start = i;
                    maxLen = len;
                }
            }

        }
    }
    return s.substr(start,maxLen);

}

int main()
{

    string s = "babd";
    string ans = longestPalindrome(s);
    cout<<ans<<endl;

    return 0;
    
}


