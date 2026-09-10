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


        int zeros=0,ones=0;

        vector<int>a(n);
        for(auto& x:a)
        {
            cin>>x;
            if(x==0)zeros++;
        }

        /*

        first and last problem should be easy 

        In one operation : he can choose two problems and swap them 

        //Min ops to make first and last problem easy or report if it is impossible to do so        
        */
       if(zeros>=2)cout<<a[0]+a[n-1]<<'\n';
       else cout<<-1<<'\n';        
    }
    return 0;
}