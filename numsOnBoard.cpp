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
        int l,r;
        cin>>l>>r;

        /*

        Beautiful number if :  it is equal to sum of all numbers on the board
        Erase any number from the board
        

        Find minimum number of numbers to be deleted from the board to have atleast one beautiful number on the board
        

        */
       //If there is no zero on the board initially -> All the numbers have same sign -> so no subset of numbers can have sum of 0 -> Answer = r-l

       // so we need to keep a subset of maximum size whose sum is 0

       if((r<0 )|| (l>0))
       {
            cout<<abs(r-l)<<'\n';
            continue;
       }

       int m = min(r,-l);
       int ans = max(0,r-l-2*m-1);
       cout<<ans<<'\n';
    }
    return 0;
}