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
        int n,m,k;
        cin>>n>>m>>k;

        string s;
        cin>>s;


        //Width = 1m, length=n
        //Cant swim in water for than k meters

        //Each segment contains either log, water or crocodile

        //on surface -> can jump forward for no more than m  meters
        //in water ->Can only swim to next river segment 
        //And can't land on the segment with a crocodile in any way
        //Determine if he can reach the bank

        //dp[i] = min number of meters that need to be swum to reach ith cell

    
    }

    return 0;
}