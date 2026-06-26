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

        //Either remove first char of second char 
        //Find number of distinct strings that can be obtained



        // Op2 before Op1 == Doing op1 twice
        
        ll ans = 0;
        vector<bool>vis(26,false);

        for(int i = 0;i<n;i++)
        {
            int c = s[i]-'a';

            if(!vis[c])
            {
                ans+=n-i;
                vis[c] = true;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

// ababa

// aaba
// aba
// aa
// a

// ba
// a
// b



// baba
// aba
// aa
// a
// ba
// a
// b

// bba
// ba
// a
// b