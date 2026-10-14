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


        /*
        We can play only one game
        n+1 slots are there -> and these slots are to be filled with an array of integers
        0<=a[n+1]<=m

        And then ai = ai+1 mod i 

        After every slot is asssigned with an integer, there are exactly k distinct values in the entire screen 

        Determine number of ways to assign an integer into slot n+1


        Cases: a[n+1] = 0 -> every vlaue of a is 0 -> So there is only 1 distinct value 

        if 1<= a[n+1] <=n  -> There exists index p = a[n+1] 
        
        */


        int ans=0;


    
    }

    return 0;
}