#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(string s,int n)
{

    //We can remove any substirng and put it's characters back in the string at nay position

    vector<int>a(2);
    for(auto &x:s)
    {
        if(x=='(')a[0]++;
        else a[1]++;
    }

    return a[0] == a[1];
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

        cout<<(solve(s,n)?"Yes":"No")<<endl;
    }

    return 0;
}