#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define all(a) a.begin(),a.end()

bool solve(vector<int>&a,int n)
{
    /*

    Choose k and a subsequence of a, and for each element of this subsequence add k to all elements

    Determine if we can sort the array by doing this operation once only
    */


    if(is_sorted(all(a)))return true;


    int maxi = 0;
    for(int i =0;i<n-1;i++)
    {
        maxi = max(maxi,a[i] - a[i+1]);
    }


    for(int i =1;i<n;i++)
    {
        if(a[i-1] > a[i])a[i]+=maxi;
    }

    return is_sorted(all(a));
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
        for(auto&x:a)cin>>x;

        cout<<(solve(a,n)?"Yes":"No")<<endl;
    
    }

    return 0;
}