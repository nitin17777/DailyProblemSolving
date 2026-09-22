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

      
        //Height of ith section is ai

        /*

        Chooses 2 indices i and j -> picks jth section and moves it backwards to position i

        subarray: ai ,ai+1, ai+2....aj-1, aj becomes aj -(j-i), ai+1, ai+1 + 1.....
        

        Flat if continguous segment of sections have equal height

        find max possible length of flat part of the road


        //Relative difference will always remain same
        

        */

        vector<ll>b(n);

        for(int k = 0;k<n;k++)
        {
            ll x;
            cin>>x;

            //converting b[k] into x- it's 1 based index
            b[k] = x-(k+1);
        }


        //Since consecutive values are easy to find afterwrds
        sort(b.begin(),b.end());


        //removing dups now
        b.erase(unique(b.begin(),b.end()), b.end());

        int best = 1,cur = 1;

        for(int i=1;i<b.size();i++)
        {
            if(b[i]==b[i-1]+1)cur++;

            //Increase window size otherwise
            else cur = 1;

            //Finding best window now
            best = max(best,cur);
        }
        cout<<best<<'\n';
    }
    return 0;
}