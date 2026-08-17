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
        int n,x;
        cin>>n>>x;

        //k = 0 initially

        //choose book at the top->Discard and k = k OR v

        //Determine if his knowledge could become x 

        int s = 0;
        int a[100000];

        //If a bit is converted to '1' , it can ever become 0 again
        
        // a number y is valid if every 1 bit of y is also a 1 bit of x : x|y = x

        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<n;j++)cin>>a[j];
            
            for(int j = 0;j<n;j++)
            {
                if((x|a[j] )!= x)break;
                s|=a[j];
            }
        }
        cout<<((s==x)? "Yes\n" :"No\n");
    }
    return 0;
}