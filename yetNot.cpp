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
        string tt;
        cin>>tt;


        int n= tt.size();
        /*

        b-> Deletes last lowercase letter from the word
        B-> Deletes last uppercase letter from the word

        Determine final output string       
        */

        string s = "";

       vector<int>up,down;
       vector<bool>del;

       for(int i=0;i<n;i++)
       {
            if(tt[i]=='B')
            {
                if(!up.empty())
                {
                    int idx = up.back();
                    up.pop_back();

                    del[idx] = true;
                }
                continue;
            }

            if(tt[i] == 'b')
            {
                if(!down.empty())
                {
                    int idx = down.back();
                    down.pop_back();
                    
                    del[idx] = true;   
                }
                continue;
           }

           int idx = s.size();
           s+=tt[i];

           del.push_back(false);

           if(isupper(tt[i]))up.push_back(idx);
           else down.push_back(idx);
       }
        for(int i = 0;i<s.size();i++)
        {
            if(!del[i])cout<<s[i];
        }
       cout<<'\n';
    }

    return 0;
}