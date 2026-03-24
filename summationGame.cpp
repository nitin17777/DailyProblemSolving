#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int>&a,int k,int x)
{
    int n = a.size();

    /*

    Moves: Alice will rmeove at most k elements from arr
            Bob will multiply at most x elements of arr by -1


    Alice wants to maximise the sum of the elements of array and bob wants to minimise the sum 

    Find the final sum of array after the game ends

    Alice starts the game
    */

    vector<ll>a(n+1);
    sort(a.rbegin(),a.rend());

    //Building prefix sum: 
    for(int i = 1; i <=n;i++)
    {
        a[]

    }






}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        vector<int>a(n);
        for(auto &x:a)cin>>x;

        cout<<solve(a,k,x)<<endl;
        
    }
    return 0;
}