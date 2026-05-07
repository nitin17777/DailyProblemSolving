#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<ll>&a,int n)
{
    /*Assign ai = ai +ai+1 , and each index can be chosen at most once

    find max number of positive numbers in final array

    */

    //Add if adding the next number would result in positive number and mark that index visited

    

    //if not visited + adding will conver negative to positive
    int ans = 0;

    for(int i = n-2; i>=0; i--)
    {
        if(a[i+1] > 0)
        {
            a[i] +=a[i+1];
        }
    }

    for(auto&x:a)if(x>0)ans++;
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

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    
    }

    return 0;
}

