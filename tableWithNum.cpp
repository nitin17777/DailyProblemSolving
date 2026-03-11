#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,int h, int l)
{
    int n = a.size();

    vector<int>freq(n);
    for(int i =0;i<n;i++)
    {
        freq[a[i]]++;
    }
    sort(freq.rbegin(),freq.rend());

    int maxFreq=freq[0];

    return maxFreq/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,h,l;
        cin>>n>>h>>l;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        cout<<solve(a,h,l)<<endl;
        
    }
    return 0;
}