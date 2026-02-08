#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        vector<int>a(3);
        for(auto&x:a)cin>>x;

        sort(a.begin(),a.end());

        if(a[1] != a[2])cout<<"No"<<endl;

        else 
        {
            cout<<"Yes"<<endl;
            cout<<a[0]<<" "<<a[0]<<" "<<a[2]<<endl;
        }
    }
    return 0;
}