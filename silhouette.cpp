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

        vector<int>b(n);
        for(auto&x:b)cin>>x;

        //Shadow bi = sum of all elements in ai that are strictly smaller than ai

        sort(b.begin(),b.end());
        vector<int>a(n);

        if(b[0] != 0)
        {
            cout<<'0'<<'\n';
            continue;
        }

        


    
    }

    return 0;
}