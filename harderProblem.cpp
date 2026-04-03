#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>&a,int n,int maxi)
{
    /*

    Construct an array b such that ai is mode of sequence [b1,b2,b3..bi]

    */

    //If a[i] is already used ->Fill it with any unused number and move ahead

    unordered_set<int>used;
    
    vector<int>b(n,0);

    for(int i = 0; i<n; i++)
    {
        if(used.find(a[i]) == used.end())
        {
            b[i] = a[i];
            used.insert(a[i]);
        }
    }


    //Collecting unsed number now
    queue<int>q;
    for(int i = 1; i<=n;i++)
    {
        if(used.find(i) == used.end())q.push(i);
    }

    for(int i = 0;i<n;i++)
    {
        if(b[i] == 0)
        {
            b[i] = q.front();
            q.pop();
        }
    }
    return b;
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
        int maxi = 0;

        for(auto &x:a)
        {   cin >> x;
            maxi = max(maxi,x);
        }

        vector<int>ans = solve(a,n,maxi+1);
        for(auto &x:ans)cout<<x<<" ";

        cout<<endl;  
    }
    return 0;
}