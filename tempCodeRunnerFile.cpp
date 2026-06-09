#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(string&s,int n,int k)
{
    /*

    Cost of bracket string = length of it's longest subsequence that is a bracket 

    Remove at most k chars from string s so that cost is minimised 

    //1 if that char is removed else 0 at that position
    */

    string ans(n,'0');

    stack<int>st;

    for(int i = 0;i<n;i++)
    {
        if(s[i] == '(')st.push(i);

        else 
        {
            if(!st.empty())
            {
                st.pop();

                if(k > 0)
                {
                    ans[i]='1';
                    k--;
                }
            }
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;


        string s;
        cin>>s;

        string ans = solve(s,n,k);

        for(auto & x:ans)cout<<x;

        cout<<endl;
    
    }

    return 0;
}