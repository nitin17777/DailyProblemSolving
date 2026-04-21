#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 676767677;


// vector<int>solve(int x,int y)
// {

//     /*

//     f(a) = number of ways to partition a into one or more subarrays :

//     Each element in exactly one subarray and all the subarrays have same sum


//     Find min value of f(a) over all arrays a of lenght x+y : x = number of 1s and y = number of -1 in any order
//     */


// }


// Counting number of divisors
int countDiv(int n)
{
    int cnt = 0;

    for(int i = 1;i*i<=n;i++)
    {
        if(n%i == 0)
        {
            cnt++;
            if(i != n/i)cnt++;
        }
    }
    return cnt;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int x,y;
        cin>>x>>y;

        int D = abs(x-y);

        int res;

        //Because in this case sum will get 0 and there will only be one way remaining
        if(x==y)res = 1;

        else res = countDiv(D);

        cout<< res%MOD <<endl;

        vector<int>ans;

        //Pushing 1 first and -1 afterwards

        for(int i = 0;i<x;i++)
        {
            ans.push_back(1);
        }

        for(int i = 0;i<y;i++)
        {
            ans.push_back(-1);
        }

        for(auto & x:ans)cout<<x<<" ";
        
        cout<<endl;
    }

    return 0;
}