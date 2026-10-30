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
        int n,k;
        cin>>n>>k;

        //difference bw number of chars 0 and 1 in s is at most 1

        //there are exactly k indices i: si == si+1

        string s = "";

        if(n>1 && k == n-1)
        {
            cout<<-1<<'\n';
            continue;
        }

        k=n-k;

        int c0 = (n+1)/2;
        int c1 = n/2;


        for(int i= 0;i<=k;i++)
        {
            if(i&1)
            {
                if(i+2 > k)while(c0--)cout<<0;

                else
                {
                    c0--;
                    cout<<0;
                }
            }

            else
            {
                if(i+2>k)while (c1--) cout << 1;

                else
                {
                    c1--;
                    cout<<1;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}