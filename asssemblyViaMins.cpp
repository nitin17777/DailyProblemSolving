#include<bits/stdc++.h>
#define ll long long
using namespace std;
      
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

        vector<int>b(n*(n-1)/2);
        for(auto &x:b)cin>>x;

        sort(b.begin(),b.end());
        //we have to Restore the original array
    
        int idx = 0;
        for(int cnt =n-1;cnt>=1;cnt--)
        {
            cout<<b[idx]<<" ";
            idx+=cnt;
        }
        cout<<1000000000<<'\n';
    }

    return 0;
}


// 3 3 3 5 5 7 , n=4 

// 3 5 7 8


// 1 3 1
// 1 3 4
