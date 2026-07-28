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

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        //make the array ascending 

        //select any 3 indices : x y z and replace ax with ay -az


        if(a[n-2]>a[n-1])
        {
            cout<<-1<<endl;
        }

        else 
        {
            if(a[n-1]<0)
            {
                if(is_sorted(a.begin(),a.end()))
                {
                    cout<<0<<endl;
                }
                else cout<<-1<<endl;
            }

            else
            {
                cout<<n-2<<endl;
                for(int i=0;i<n-2;i++)
                {
                    cout<<i+1<<" "<<n-1<<" "<<n<<endl;
                }
            }
        }    
    }
    return 0;

}