#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>&a,int n,int m)
{
    /*

    Anna makes the first move

    Anna choses any element ai and reverse the sequence of this element
    Sasha concatenates and removes two numbers and insert them back

    Game ends when after Anna's move exactly one number is left in the list : and if this number is not less than 10^m -> Sasha wins, else Anna
 
    
    
    */
}
      
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


        vector<int>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,n,m)<<'\n';
    
    }

    return 0;
}