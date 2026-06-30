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

        vector<int>a(n),b(n);

        for(auto& x:a)cin>>x;
        for(auto& x:b)cin>>x;

        if(a==b)
        {
            cout<<"Yes"<<'\n';
            break;
        }

        /*

        Cann we make a equal to b??


        We can always decrease single number to any less

        left or right greater and bi%ai ==0
        
        */

        if(a[0] < b[0])
        {
            if(a[1] > a[0])continue;

            else
            {
                cout<<"No"<<'\n';
                break;
            }
        }

        if(a[n-1]<b[n-1])
        {
            if(a[n-2]>a[n-1])continue;

            else
            {
                cout<<"No"<<'\n';
                break;
            }
        }

        for(int i=1;i<n-1;i++)
        {
            if(a[i]<b[i])
            {
                if(a[i-1] > 0 || a[i+1] > 0)continue;

                else 
                {
                    cout<<"NO"<<'\n';
                    break;
                }
            }
        }
        cout<<"Yes"<<'\n';
    }

    return 0;
}