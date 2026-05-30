#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{

    /*

    Alice has to make group but she can only call 2 people at a time


    determine min groups to be made

    
    */

    sort(a.begin(),a.end());

    int i = 0,j=n-1;

    int ans = 0;
    while(i<j && a[i] != a[j])
    {
        i++;
        j--;
        ans++;
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
        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    }

    return 0;
}