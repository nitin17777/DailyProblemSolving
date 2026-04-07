#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n,int x,int y)
{
    

    /*

    Array is such that: max prefix position of b = smallest index i : b1 + b2+ ...bi = max(b1+ )
    

    a should be such that: ai is either 1 or -1 for all indices
    max prefix posi of a is x
    max suffix posi of a is y

    */
   x--;
   y--;
    vector<int>a(n,1);

    //Now right side of x
    int e = -1;
    for(int i=x+1;i<n;i++)
    {
        a[i] = e;
        e*=-1;
    }


    e = -1;
    for(int i =y-1;i>=0;i--)
    {
        a[i] = e;
        e*=-1;
    }
    return a;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>ans = solve(n,x,y);
        for(auto&x:ans)cout<<x<<" ";

        cout<<endl;
    
    }

    return 0;
}