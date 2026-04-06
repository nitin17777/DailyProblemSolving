#include<bits/stdc++.h>
using namespace std;

int f(int a,int b)
{
    if(a>b)return 1;
    if(a==b)return 0;
    
    return -1;
}

int solve(vector<int>&a, int n)
{
    /*

    Each card has value : 1-10

    Each player gets two cards which are face down

    Player wins if he wins most number of rounds

    Return the possible ways to calculate number of ways game could happen that suneet end up as the winner
    
    a[0],a[1] ->suneet
    a[2],a[3] ->slavic
    */

    int ans = 0;

    //Simulating full game:
    if(f(a[0],a[2]) + f(a[1],a[3]) > 0)ans++;

    if(f(a[0], a[3]) + f(a[1], a[2]) > 0)ans++;


    if(f(a[1],a[2]) + f(a[0],a[3]) > 0)ans++;

    if(f(a[1], a[3]) + f(a[0],a[2]) > 0)ans++;

    return ans;

}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        vector<int>a(4);
        for(auto & x:a)cin>>x;

        cout<<solve(a,4)<<endl;
    }

    return 0;
}