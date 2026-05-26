#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canReach(string s, int minJump, int maxJump)
{
    //Determine if we can reach the last cell by jumps or not
    //IF we can reach j : i +minJump <= 

    int n = s.size();
    vector<bool>dp(n,false);
    dp[0] = true;

    //dp[i] = can we reach index i 
   
    int reachable = 0;

    for(int i = 1;i<n;i++)
    {
        if(i-minJump >=0 && dp[i-minJump])reachable++;

        if(i-maxJump -1 >= 0 && dp[i-maxJump-1])reachable--;

        if(reachable > 0 && s[i] == '0')dp[i]=true;
    }
    return dp[n-1];
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(canReach("011010",2,3)?"True":"False")<<endl;
    return 0;
}