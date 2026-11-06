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
        int n,k;
        cin>>n>>k;

        vector<ll>a(n);
        for(auto&x:a)cin>>x;

        //a = donation in each stream
        //Pleasant donation if : It's size >= average of previous donations
        //Stream pays off if : receives exactly k pleasant doantions

        //Determine the order of  donation

        sort(a.begin(),a.end());

        int cnt = 0;

        for(int i = n-1; i>=0 && a[i] == a[n-1];i--)cnt++;
        
        if(k<cnt)
        {
            cout<<"No\n";
            continue;
        }


        cout<<"Yes\n";

        //Top k in ascending 
        for(int i = n-k;i<n;i++)cout<<a[i]<<" ";

        //Remaining n-k in descending
        for(int i = n-k-1;i>=0;i--)cout<<a[i]<<" ";

        cout<<'\n';
    }

    return 0;
}