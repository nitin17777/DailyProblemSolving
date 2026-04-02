#include<bits/stdc++.h>
using namespace std;

bool solve(string s,int n)
{
    /*

    Alice aims for true, bob aims for false

    IF AND is there -> choose any one AND and replace it with it's evaluation
    Do the same if OR is there
    
    */

    //Alice can easily win by placing one OR after first or before last boolean
    if(s[0] == '1' || s[n-1] =='1')return true;

    //otherwise if two consecutive 1s are there, Alice can instantly place one OR there to always win
    for(int i =1;i<n;i++)
    {
        if((s[i] == '1') && (s[i-1] == s[i]))return true;
    }
    return false;
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