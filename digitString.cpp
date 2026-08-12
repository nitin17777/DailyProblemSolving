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
        string s;
        cin>>s;

        //Find min number of elements required to make the string beautiful

        int pref2=0,suf = 0;

        for(char x:s)
        {
            if(x=='1' || x=='3')suf++;
        }

        int ans = suf;


        //boundary from left to right
        for(char x:s)
        {
            if(x=='2')pref2++;
        
            if(x=='1' || x=='3')suf--;

            ans = max(ans, pref2+suf);
        }
        cout<<s.size()-ans<<'\n';
    }
    return 0;
}