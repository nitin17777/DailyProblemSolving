#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(string s,string t,int n)
{

    /*

    Replace si with si XOR s i-l+1

    Determine if it is possible to convert s to t
    */

    set<char>st(s.begin(),s.end());
    if(st.size() == 1 && s[0] == '0')return s == t;

    int idx1=0;
    for(int i =0;i<n;i++)
    {
        if(s[i] == '1')
        {   
            idx1 = i;
            break;
        }
    }

    //Now check if before idx there is 1 in t -> if exists then simply return NO

    for(int i =0;i<idx1;i++)
    {
        if(t[i] == '1')
        {
            return false;
        }
    }
    return true;
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

        string s,t;
        cin>>s>>t;

        cout<<(solve(s,t,n)?"Yes":"No")<<endl;
    }

    return 0;
}