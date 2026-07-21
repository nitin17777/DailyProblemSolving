#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxActiveSectionsAfterTrade(string s)
{
    //We can make atmost 1 trade to maximise active sessions
    //Convert block of contiguous 1 to 0 and then  some block of 0s to 1

    //Return max number of active sessions after making optimal trade

    int ones = 0;

    string t = '1'+s+'1';

    for(char&c:s)if(c=='1')ones++;

    int best = 0;

    int m = t.size();

    int i = 0;


    while(i<m)
    {
        if(t[i] == '0')
        {
            // 0 block
            int j = i;
            while(j<m && t[j] =='0')j++;
            int leftZero = j-i;


            //following One block
            int k = j;
            while(k<m && t[k]=='1')k++;


            //internal one block
            if(k<m)
            {
                int l = k;
                while(l<m && t[l] == '0')l++;

                //right zero block
                if(l>k)
                {
                    int rightZero = l-k;
                    best = max(best,leftZero+rightZero);
                }
            }
            i=j;

        }
        else i++;
    }
    return best+ones;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<maxActiveSectionsAfterTrade("0100")<<endl;
    
    return 0;
}