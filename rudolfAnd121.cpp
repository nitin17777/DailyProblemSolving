#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool solve(vector<int>&a,int n)
{
    //Decrease itself by 2 or ,previous and next element by 1 
    //Determine if he can make  all elements equal to zero or not


    for(int i = 0;i<n-2;i++)
    {
        if(a[i] <0)return false;

        int op = a[i];
        a[i+1] -= 2*op;
        a[i+2] -= op;
    }

    if(a[n - 1] != 0 || a[n - 2] != 0)return false;
    
    return true;
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

        cout<<(solve(a,n)?"Yes":"No")<<endl;
    }

    return 0;
}