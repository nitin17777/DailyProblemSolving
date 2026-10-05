#include<bits/stdc++.h>
#define ll long long
using namespace std;


//open = number of ( used
//close = number of  ) used

void solve(string s,int open,int close,int n,vector<string>&ans)
{
    //base case:When string of required length is formed successfully
    if(s.size() == 2*n)
    {
        ans.push_back(s);
        return;
    }

    //Add opening bracket
    if(open<n)
    {
        solve(s+'(',open+1,close,n,ans);
    }

    //Add closing bracket
    if(close<open)
    {
        solve(s+')',open,close+1,n,ans);
    }
}

vector<string> generateParenthesis(int n)
{

    //We have to generate all combinations of well formed parentheses

    vector<string>ans;

    solve("",0,0,n,ans);
    return ans;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>ans=generateParenthesis(3);
    for(auto&x:ans)cout<<x<<" ";

    cout<<'\n';
    return 0;
}