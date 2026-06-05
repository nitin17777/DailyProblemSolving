#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>&a,int n)
{
    /*

    b is subsequence of a and contrast of b = contrast of a

    find min possible size of array b
    */

   n = unique(a.begin(),a.end()) - a.begin();

   int ans = n;
    //now find indices : ai-1 < ai <ai+1 : We can remove ai from here and contrast will not be affected
    for(int i = 1;i<n-1;i++)
    {
        if((a[i] > a[i-1]) && (a[i] < a[i+1]) || (a[i] < a[i-1]) && (a[i] > a[i+1]))ans--;
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
        for(auto&x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    }
    return 0;
}