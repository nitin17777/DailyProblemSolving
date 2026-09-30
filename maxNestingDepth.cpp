#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxDepth(string s)
{

    int n = s.size();
    
    //Find the maximum number of brackets which are open at point

    stack<char>st;
    int cnt = 0;
    int ans = 0;

    for(auto &x:s)
    {
        if(x=='(')
        {
            st.push(x);
            cnt++;
            ans=max(cnt,ans);
        }

        if(x==')')
        {
            st.pop();
            cnt--;
        }
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxDepth("(1+(2*3)+((8)/4))+1")<<endl;

    return 0;
}