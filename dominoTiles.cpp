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

        //Each tile should be marked 0 o 1
        //replace every ? with 0 or 1

        //Two neighbouring tiles form a dominoof weight si + si+1
        //We have to find : Different ways to fill all ?


        //Since 2 consecutve dominos must ahve different weight : si != si+2 should be satisfied

        //so si+2 = 1-si

        int ans = 0;

        for(int fs = 0;fs<=1;fs++)
        {
            for(int sec = 0;sec<=1;sec++)
            {
                bool valid = true;

                //Checking position 0, if it is already known it must match our chosen value
                if(s[0] != '?' && s[0]-'0' != fs)valid = false;

                if(n>=2 &&s[1] != '?' && s[1]-'0'!=sec)valid = false;

                if(!valid)continue;

                for(int i = 2;i<n;i++)
                {
                    int prev = (i%2 ==0)?fs:sec;
                    int exp = 1-prev;

                    if(s[i] != '?' &&s[i]-'0' != exp)
                    {
                        valid = false;
                        break;
                    }
                }
                if(valid)ans++;
            }
        }
        cout<<ans<<'\n';    
    }
    return 0;
}