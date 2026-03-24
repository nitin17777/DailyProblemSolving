#include<bits/stdc++.h>
using namespace std;

int solve(int n,const vector<int>&b,int a)
{
    /*

    m teachers are together chasing david now

    During each move: David goes to adj cell or stays in the same cell and same thing for teachers as well

    Determine the moves taken by teacher to catch David

    n = number of cells on the lineq

    a = David's cell number
    */
   
    //To get first element >= a
    auto it = lower_bound(b.begin(),b.end(),a);
    
    //Case 1 :No teacher on left
    if(it == b.begin())
    {
        int R = *it;
        return R - 1;
    }

    //Case 2 : If no teacher on right
    if(it == b.end())
    {
        int L = b.back();
        return n-L;
    }

    //Case 3 :  Stuck in bw two teachers

    int R = *it, L = *(it-1);

    return (R-L)/2;
}
    

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;

        vector<int>b(m);
        for(auto & x:b)cin>>x;

        //Sorting must take place just once, and not for every query
        sort(b.begin(),b.end());


        while(q--)
        {
            int a;
            cin>>a;
            cout<<solve(n,b,a)<<'\n'; 
        }
    }
    return 0;
}