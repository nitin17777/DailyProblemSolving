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
        int n,m;
        cin>>n>>m;
        


        //Each detector covers a segment of consecutive spots

        /*

        Determine min number of additional detectors needed so that we would surely be caught

        
        */

        if(n==1)
        {
            cout<<0<<'\n';
            continue;
        }

        //Each detector covers one continuous interval 

        vector<pair<int,int>>act;

        int k = (n+1)/2;

        cout<<(n+1)/2 <<'\n';

        for(int i = 1;i<n;i++)
        {
            cout<<i<<" "<<i<<'\n';
        }
    }

    return 0;
}