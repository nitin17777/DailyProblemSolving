#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    //max - min = GCD of all elements (in that subsequence)




    //Determine the number of good arrays in the given array


    int g = a[0];
    for(auto &x:a)g = gcd(g,x);


    //now min and max would be the multiple of g for sure

    //max = M.g and min = m.g


    // max - min = g (given condition)=> M-m = 1

    // So problem simplifies to M - m = 1

    // so check : abs(x-y) = gcd(x,y) for adjacent pairs

    int ans = 0;

    for(int i = 1;i<n;i++)
    {

        //checking only adjacent elements because only 2 distinct values are allowed
        if(abs(a[i] - a[i-1]) == gcd(a[i],a[i-1]))ans++;
    }
    return ans;
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
        for(auto &x:a)cin>>x;

        cout<<solve(a,n)<<endl;   
    }

    return 0;
}