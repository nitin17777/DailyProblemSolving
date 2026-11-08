#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<string,bool>dp;
bool solve(string s1,string s2)
{
    if(s1==s2)return true;

    //Impossible if different character frequencies
    string a=s1,b=s2;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a!=b)return false;



    //Making unique key represenitign current pair of strings
    string key = s1+"#"+s2;

    //if this pair was already solved -> use the stored result 
    if(dp.count(key))return dp[key];

    int n = s1.size();
    
    //Trying every possible split
    for(int i=1;i<n;i++)
    {
        //Case 1 : NO swappping

        //First i chars of s1
        string left1 = s1.substr(0,i);
        
        //Remaining chars of s1
        string right1 = s1.substr(i);

        //Left part matches with left and right part matches with right 
        bool noSwap = solve(left1,s2.substr(0,i)) && solve(right1,s2.substr(i));

        //If both parts match -> Entire strings are scramble
        if(noSwap)return dp[key] = true;

        //Case 2 : swapping
        //left part of s1 now matches right part of s2 and right part of s1 now matches left part of s2

        bool swapped = solve(left1, s2.substr(n-i)) && solve(right1, s2.substr(0,n-i));

        if(swapped)return dp[key] = true;
    }
    //if no split position works -> these strings are not scrambles
    return dp[key] = false;
}

bool isScramble(string s1, string s2)
{
    
    //Determine if s2 is scrambled string of s1


    //At every split : We have two choices : either substrings remain same or they get swapped
    if(s1.size() != s2.size())return false;

    return solve(s1,s2);

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(isScramble("great","rgeat")?"true" : "false")<<endl;

    return 0;
}