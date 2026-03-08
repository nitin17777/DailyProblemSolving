#include<bits/stdc++.h>
using namespace std;


pair<int,int> solve(string &s)
{

    int n = s.size();

    int ones=count(s.begin(),s.end(),'1');

    for(int i = 1;i<n-1;i++)
    {
        if(s[i-1] == '1' && s[i+1] == '1')s[i] = '1';
    }
    int maxi = count(s.begin(),s.end(),'1');

    for(int i = 1;i<n-1;i++)
    {
        if(s[i-1] == '1' && s[i+1] == '1')s[i] = '0';
    }

    int mini = count(s.begin(),s.end(),'1');

    return {mini,maxi};

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
        string s;
        cin>>s;

        pair<int,int>ans = solve(s);
        cout<<ans.first<<" "<<ans.second<<endl;
        
        
    }
    return 0;
}