#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        long long R, X,D;
        
        int n;
        cin>>R>>X>>D>>n;

        string s;
        cin>>s;


        int ans = 0;
        for(char c:s)
        {
            if(c=='1')
            {
                //Taking the smallest possible rating greedily for future div2 chances
                R = max(0LL, R-D);
                ans++;
            }

            else
            {
                if(R<X)
                {
                    R = max(0LL,min(R,X-1)-D);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}