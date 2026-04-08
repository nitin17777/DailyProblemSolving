#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n,int k)
{

    //values of ai at sepcial index  is same 

    /*

    In one move we can select a move such that range contains that special index and then flip all bits of this selected range

    x = a[k]

    Determine the number of steps to make all the elements of array equal to x

    
    */
   int x = a[k-1];
   vector<int>b(n+2);

   //Padding 
   b[0] = 1,b[n+1] = 1;

   //Constructing new array b now 
   for(int i=1;i <= n;i++)
   {
        if(a[i-1] == x)b[i] = 1;
        else b[i] = 0;
   }


   int x1 = 0,x2 =0;
   for(int i = 0;i<=n;i++)
    {
        if(b[i] != b[i+1])
        {
            if(i<k)x1++;

            else x2++;
        }
  }
   return max(x1,x2);
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

        cin>>k;
   
        cout<<solve(a,n,k)<<endl;
    }

    return 0;
}




