#include<bits/stdc++.h>
using namespace std;

vector<int>solve(vector<int>&a,int n)
{

    //Find the array satisfying any 2 given conditions

    vector<int>b(n,1);

    int g = 0;

    for(int i =0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            if(a[i] == a[j])
            {
                b[i] = 1;
                b[j] = 2;
            }
        }
        g = j;
    }

    for(int i = g;i<n;i++)
    {
        for(int j = g+1;j<n;j++)
        {
            if(a[i] == a[j])
            {

            }
        }
    }
    //select any two indices with same elemnts : 
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
        for(auto & x:a)cin>>x;

        vector<int>ans = solve(a,n);

        for(auto &x:ans)cout<<x<<" ";

        cout<<endl;        
    }
    return 0;
}