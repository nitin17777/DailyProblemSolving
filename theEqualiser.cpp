#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int>&a,int k)
{

    /*

    Shanak will play first
    Last player to make a move wins

    On their turn each player chooses a number and decremnent it by 1
    
    Shaunak can do this once: all elements in ai are set to given k

    DEtermine is shaunak can win or not

    
    */

    int n = a.size();

    int total = accumulate(a.begin(),a.end(),0);

    //If total sum is odd shaunak will always win
    if(total % 2 != 0)return true;

    int after = n*k;

    if(after%2 == 0)return true;

    return false;
}

      
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
        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<(solve(a,k)?"Yes":"No")<<endl;
    }

    return 0;
}