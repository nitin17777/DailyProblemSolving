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

        /*

        /Construct perm such that i*pi is composite for each i , else return -1       
        
        Composite num => number having any other divisor than 1 and itself

        Smallest composite number => 4 = 1,2,4
        */
        vector<int>ans(n);
        if(n<4)
        {
            cout<<-1<<'\n';
            continue;
        }

        
        else
        {
            for(int i = 0;i<n;i++)ans[i] = i+1;

            ans[0]=4;
            ans[3]=1;       
        }

        for(auto&x:ans)cout<<x<<" ";

        cout<<'\n';
    }
    return 0;
}