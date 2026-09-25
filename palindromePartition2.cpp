#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPal(string s)
{
    int n = s.size();

    int left = 0,right=n-1;

    while(left<right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else return false;
    }
    return true;
}

int minCut1(string s)
{
    int n = s.size();

    //Partition s such that every substring of partition is a palindrome
    //Return min number of cuts needed for palindrome partitioning this s
    

    //dp[i] = min number of cuts needed to partition s[0...i]
    vector<int>dp(n,0);
    dp[0]=1;


    //When s[left...right] is not palindrome, instead of moving left ansd right immediately, try every possible starting point for the last palindrome
    int left = 0;
    int ans = 0;

    for(int right= 1;right<n;right++)
    {
        string curr = s.substr(left,right-left+1);

        if(!isPal(curr))
        {
            left=right;
            dp[right]=dp[right-1];
        }
        else dp[right] = dp[right-1]+1;
    }
    return dp[n-1]-1;



    //Problem with above approach is : the string might not immediately be a palindrome but can become palindrome later as the lenght of string increases
}


int minCut(string s)
{
    int n = s.size();

    // pal[l][r]=whether s[l....r] is palindrome 
    vector<vector<bool>>pal(n,vector<bool>(n,false));

    //building plaindrome table for all substrings
    for(int len = 1;len<=n;len++)
    {
        for(int l = 0;l+len-1<n;l++)
        {
            int r = l+len-1;

            if(s[l]==s[r] && (len<=2 || pal[l+1][r-1]))pal[l][r] = true;
        }
    }

    vector<int>dp(n);
    for(int i = 0;i<n;i++)
    {

        //If entire s[0...i] is palindrome, we don't need any cut
        if(pal[0][i])
        {
            dp[i]=0;
            continue;
        }

        dp[i]=i;//Max possible cuts ; worst case
        for(int j=1;j<=i;j++)
        {
            if(pal[j][i])
            {
                dp[i] = min(dp[i],dp[j-1]+1);
            }  
        }
    }
    return dp[n-1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minCut("aab")<<endl;

    return 0;
}