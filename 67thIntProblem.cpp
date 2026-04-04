#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<int>a(7);
        for(auto & x:a)cin>>x;

        sort(a.begin(),a.end());

        int sum = 0;
        for(auto & x:a)
        {
            sum += x;
        }
        sum-=a[6];

        sum = -sum;

        sum += a[6];       

        cout<<sum<<endl;

    }
}