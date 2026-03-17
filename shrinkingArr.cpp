#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();
     
    //Beautiful if it consists of atleast two elements and there exists a position i such that | bi - bi+1 | <= 1

    //we can perform the following ops: 
    // insert min(ai,ai+1) <= x <= max(ai,ai+1) and remove them both

    //Return the min number of ops to make arr beauttiful

    if(n == 2 && abs(a[0] - a[1] > 1))return -1;

    //Basic check for already beautiful arr
    for(int i =1;i<n;i++)
    {
        if(abs(a[i] - a[i-1]) <= 1)return 0;
    }

    //We can convert to beautiful arr if a peak or valley exists
    for(int i = 1;i+1<n;i++)
    {
        if(a[i-1] < a[i] && a[i] > a[i+1])return 1;

        if(a[i-1] > a[i] && a[i] < a[i+1])return 1;
    }

    return -1;
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

        cout<<solve(a)<<endl;
        
    }
    return 0;
}