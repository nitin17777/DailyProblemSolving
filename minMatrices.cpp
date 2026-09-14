#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Didn't understood some part of this problem 
      
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

        /*

        f(b) deonte the set of all min element of each row and col of b

        
        */

        if((k<n) || (k>2*n-1) )
        {
            cout<<-1<<'\n';
            continue;
        }


        vector<vector<int>>ans(n,vector<int>(n,-1));

        // Case: n==k
        int curr = 1;
        if(k==n)
        {
            for(int i=0;i<n;i++)
            {
                ans[i][i] = curr++;
            }

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        ans[i][j] = curr++;
                    }
                }
            }
        }

        else
        {
            //remaining case: n <= k <= 2*n-1
            int x = k+1-n;


            //Putting 1...x in first row
            for(int i=0;i<x;i++)
            {
                ans[0][i]=i+1;
            }

            //now from column below 1, fill x+1......2x-1
            for(int i=1;i<x;i++)
            {
                ans[i][0]=x+i;
            }

            //We have used numbers: 1....2x-1
            
            //And remaining minimums are 2x...k

            curr=2*x;
            for(int i =x;i<n;i++)ans[i][i] = curr++;


            //Filling all remaining cells with numbers greater than k now
            curr=k+1;
            for(int i =0;i<n;i++)
            {
                for(int j = 0;j<n;j++)
                {
                    if(ans[i][j] == -1)ans[i][j] = curr++;
                }
            }           
        }
        
        for(auto&row:ans)
            {
                for(auto&x:row)
                {
                    cout<<x<<" ";
                }
                cout<<'\n';
            }
            cout<<'\n';
    }

    return 0;
}