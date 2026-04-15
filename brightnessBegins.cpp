#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int k)
{
    /*

    For each bulb i = 1,2,3...n , flip the state of all bulbs j such that j is divisible by i

    After performing all ops -> We have to make number of bulbs on  = k
    
    
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
        int n;
        cin>>n;

        cout<<solve(n)<<endl;
    
    }

    return 0;
}