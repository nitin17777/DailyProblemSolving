#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n,int k)
{
    /*

    He gets piles with ceil(x/2) and floor(x/2) when divided andn this division takes 1 minute


    Wants to eat k apples, 

    He wants a pile containing exactly k apples, 

    find the min time to get k apples , if not possible return -1
    */
   int l = n,r=n;

   int cnt = 0;

   while(r!=1)
   {

    //If k lies within the current range, we are done
        if(l<=k && k <= r)break;
        {
            l = l/2;
            r = r/2 + r%2;
            cnt++;
        }
    }

    //True if k is in this range
    if(l<=k && k<=r)return cnt;
    return -1;
    }

      
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        cout<<solve(n,k)<<endl;
    
    }

    return 0;
}