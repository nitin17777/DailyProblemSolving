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

        vector<int>a(n);
        for(auto& x:a)cin>>x;

        vector<int>nextDiff(n+1);

        nextDiff[n-1] = -1;

        for(int i=n-2;i>=0;i--)
        {
            if(a[i] != a[i+1])
            {
                nextDiff[i] = i+1;
            }
            else nextDiff[i]=nextDiff[i+1];
        }

        int q;
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            l--;
            r--;

            //find 2 indices such that ai != aj and l <= i,j <= r

            if(nextDiff[l] != -1 && nextDiff[l] <= r)
            {
                //l+1 because we want final answer to be in 1 base indexing
                cout<<l+1<<" "<<nextDiff[l]+1<<endl;
            }
            else cout<<-1<<" "<<-1<<endl;
        }    
    }
    return 0;
}