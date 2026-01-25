#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n)
{
    /*

    Permutation is of size consisting of numbers from 1 to n only
    
    construct a permutation such that sum of adjacent elements is composite over every interval,if not possible return -1;    
    */

    if(n < 5)return {-1};

    vector<int>ans;
    int l = 1,r = n;
    while(l <= r)
    {
        ans.push_back(l);
        ans.push_back(r);
        l++;
        r--;
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
        vector<int>ans = solve(n);

        for(auto&x :ans)cout<<x<<" ";

        cout<<endl;
        
    }
    return 0;
}