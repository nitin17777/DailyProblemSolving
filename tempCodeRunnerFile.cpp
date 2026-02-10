#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n)
{

    //permutation of size n such that abs(pi - pi+ 1) is divisible by i


    vector<int>p(n+1);
    p[n] = n;
    p[n-1] = 1;

    for(int i = n-2;i>=1;i--)
    {
        if(i%2 == 1)
        {
            p[i] = p[i+1] +1;
        }
        else
        {
            p[i] = p[i+1] -1;
        }
    }
    return p;

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
        
        vector<int>p=solve(n);
        for(int i = 1;i<=n;i++)cout<<p[i]<<" ";

        cout<<endl;
    }
    return 0;
}