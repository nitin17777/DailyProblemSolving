#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 676767677;

int solve(vector<int>&a,int n)
{
    /*

    We have to make the array empty

    cost = ai1 * ai2 * ai3...aik

    also the chosen elements in subsequence must be non decreasing 

    Determinre the minimum total cost to remove all the elements from the array
    */


    //We will never group two elements greater than 1 together,so remove each element greater than 1 separately

    set<int>st(a.begin(),a.end());

    //edge case

    if(st.size() == 1 && a[0] ==1)return 1%MOD;

    int ans = 0;
    
    if(a.back() == 1)ans++;

    for(auto & x:a)
    {
        if(x>1)ans+=x;
    }

    return ans%MOD;
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




