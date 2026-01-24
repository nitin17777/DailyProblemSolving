#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool solve(int n,int c,int d,vector<int>&a)
{


    /* c = 2 ; d = 3
    3 9 6
    5 7 1
    11 4 8
    */

    sort(a.begin(),a.end());

    vector<int>b(n*n);
    b[0] = a[0];
    
    for(int i=1;i<n;i++)
    {
        b[i] = b[i-1] + c;
    }

    for(int i = 1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i*n + j] = b[(i-1)*n + j] + d;
        }
    }
    sort(b.begin(),b.end());
    return (a==b);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,c,d;
        cin>>n>>c>>d;

        vector<int>a(n*n);
        for(int i =0;i<n*n;i++)cin>>a[i];

        cout<<(solve(n,c,d,a)?"Yes" :"No")<<endl;        
    }
    return 0;
}