#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{

    //Choose pair of indices i,j and a[i] > a[j] and remove a[j] from the array

    //For every element check if any smaller number is there after it and count

   int cmx = 0;
 
    int mx = 0;
 
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (a[i] == mx) cmx++;
    }
 
    int res = n - cmx;


    return res;


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
        for(auto& x:a)cin>>x;

        cout<<solve(a,n)<<endl;
        
    }

    return 0;
}




