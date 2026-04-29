#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool solve(vector<int>&a,vector<int>&b,int n,int m,int k)
{

    //Determine if we can choose exactly k/2 elements from both arrays such that among the chosen elements all integers from 1 to k are included

    vector<int>cnt(k+1,0);
    for(auto &x:a)
    {
        //Marking presence of this element in a
        if(x<=k)cnt[x] |= 1;    
    }

    //marking presence in b
    for(auto&x:b)
    {
        if(x<=k)cnt[x] |=2;
    }

    //counting types now
    vector<int>c(4,0);
    for(int i = 1;i<=k;i++)
    {
        c[cnt[i]]++;
    }


    //Checking final conditions now"

    // if more than required nums are from either from one array + elements are not sufficient
    

    if(c[1] > k/2 || c[2] > k/2 || (c[1] + c[2] + c[3] != k))return false;

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
        int n,m,k;
        cin>>n>>m>>k;

        vector<int>a(n),b(m);

        for(auto& x:a)cin>>x;
        for(auto & x:b)cin>>x;

        cout<<(solve(a,b,n,m,k)?"Yes":"No")<<endl;
    }

    return 0;
}