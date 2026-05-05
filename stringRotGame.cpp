#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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

        //Find the max possible 
        int cnt = 1;
        bool yes = false;

        for(int i =1;i<n;i++)
        {
            if(s[i] != s[i-1])cnt++;
        }


        if(cnt != n && s[0] != s[n-1])cnt++;

        cout<<cnt<<endl;    
    }

    return 0;
}