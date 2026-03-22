#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>&a)
{
    int n = a.size();

    /*
    For each index i : Find the max number of indices j : j > i and ai > aj for all values of k

    We want to maximise count of j > i : k is closer to aj than to ai
     

    if k moves right(increases) : Larger number becomes closer
    if k moves left(decreases) : Smaller number becomes closer

    
    We need to find the number of elements after i that are closer to k than ai

    */

    vector<int>ans(n);

    for(int i = 0;i<n;i++)
    {
        int f1 = 0,f2 = 0;

        for(int j = i+1;j<n;j++)
        {
            if(a[i] > a[j])f1++;// - inf
            if(a[i] < a[j])f2++;//k -> +inf
        }
        ans[i] = max(f1,f2);
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

        vector<int>ans =solve(a);
        for(auto &x:ans)cout<<x<<" ";

        cout<<endl;
        
    }
    return 0;
}