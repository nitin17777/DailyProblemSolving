#include<bits/stdc++.h>
#define ll long long
using namespace std;


string solve(string&s,int k,int n)
{
    /*

    1-> We can pick si and si+2 and swap them
    2-> Pick index i and reverse the string in range (i,i+k-1)

    Find the lexicogrpahically smallest string possible
    
    
    */

    if(k%2 == 0)
    {
        sort(s.begin(),s.end());
        return s;
    }

    vector<char>odd,even;

    for(int i =0;i<n;i++)
    {
        if(i%2 == 0)even.push_back(s[i]);
        else odd.push_back(s[i]);
    }

    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());

    string ans = "";

    for(int i = 0,j=0; i<even.size() || j<odd.size(); i++,j++)
    {
        if(i < even.size())ans+=even[i];

        if(j<odd.size())ans+=odd[i];
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

        cout<<solve(s,k,n)<<endl;
    }

    return 0;
}




