#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(string s,int n)
{

    //Determine how many students will receive the ball atleast once during this process


    int fl = 0;

    for(int i = 0;i<n;i++)
    {
        if(s[i] == 'L')return i+1;
    }
    return -1;
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

        cout<<solve(s,n)<<endl;
    }

    return 0;
}