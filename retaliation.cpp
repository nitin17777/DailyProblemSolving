#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int>&a,int n)
{
    //Explodes :  1-> Decrease all elements by i
    //            2-> Decrease all elements by n-i+1;

    //Determine if it possible to explode the array using ay number of operations

    /*
    
    When both moves are done once -> Each element is decreased by n+1
    so we are basically evenly reducing all the elements first

    
    */

    //If no pattern already ->not possible
   ll diff = a[1]-a[0];
   for(int i = 2;i<n;i++)
   {
        if(a[i]-a[i-1] != diff)return false;
   }

   
    for(int i = 0; i < n; i++)
    {
        a[i] = a[i] + (diff < 0 ? diff * (n - i) : -diff * (i + 1));
    }

   return (a[0] >= 0 && a[0] % (n + 1)==0);
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

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<(solve(a,n)?"Yes":"No")<<endl;
    }

    return 0;
}