#include<bits/stdc++.h>
using namespace std;


vector<int>solve(vector<int>&a)
{
    int n = a.size();

    if(n == 1)return {1};






    //Lower bound for this array would be 2
    vector<int>arr(n,2);
    //Choose the subarray of size 3 and delete either either the smallest or largest element within it


    //For each i from 1 to n, find th emin lenght of array that contains number pi

    return arr;
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
        
        vector<int>ans = solve(a);
        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;

    }
    return 0;
}