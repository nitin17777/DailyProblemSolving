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

        vector<ll>a(n),b(n);

        for(auto& x:a)cin>>x;
        for(auto& x:b)cin>>x;

        if(a==b)
        {
            cout<<"Yes"<<'\n';
            continue;
        }

        /*

        Can we make a equal to b??


        We can always increase single number to any greater
        And applying operation on [i-1,i] : ai decreases by 1 and ai-1 increases by 1
        
        left or right greater and bi%ai ==0
        
        */

        //So simply do the operation

        for(int i = n-1;i>0;i--)
        {
            if(a[i]>b[i])
            {
                a[i-1]+= (a[i]-b[i]);
            }
        }
        cout<<((a[0] <= b[0])?"Yes":"No" )<< '\n';
    }
    return 0;
}