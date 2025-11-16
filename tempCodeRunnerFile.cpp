#include<bits/stdc++.h>
using namespace std;

int  solve(vector<int>& arr)
{
    int n = arr.size();

    sort(arr.begin(),arr.end());

    //first and last element should both be of same parity

    //if not,move from smallest element until we get to match the parity of largest digit and vice versa

    int cnt = 0;
    int i = 0; 
    for(int i=0;i<n;i++)
    {
        if((arr[i]+ arr[n-1]) % 2 == 0)
        return i;
    }
    return -1;

}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>arr(n);

        for(auto &x: arr)cin>>x;
        cout<<solve(arr)<<endl;

    }
    return 0;
}
