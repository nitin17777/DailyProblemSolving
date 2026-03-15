#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,int k,int p,int m)
{
    //Bob can play the cards that are currently placed in the first k positions in the deck

    //in each turn he plays the card form top of the deck and then places the same card back at the bottom of the deck

    //One card is called the win condition

    //ith cards costs bob ai energy 

    //Total cost of cards played must no exceed m

    //Win condition card is place at pth place in the queue

    //Determine the maximum number of times win condition card can be played ensuring the total cost doesnt exceed m

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,p,m;
        cin>>n>>k>>p>>m;

        vector<int>&a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,k,p,m)<<endl;
    }
    return 0;
}