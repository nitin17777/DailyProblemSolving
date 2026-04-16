#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(vector<string> &a)
{
    int n = a.size();

    string ans = "";

    //Return the smallest lexicographically string s
    
    for(auto & x:a)
    {
        ans = min(ans+x , x+ans);
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
        int n;
        cin>>n;

        vector<string>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a)<<endl;
    }
    return 0;
}




