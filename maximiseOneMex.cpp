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
        int n,k;
        cin>>n>>k;

        vector<int>a(n);

        for(auto&x:a)cin>>x;

        //We need to put all smallest possible numbers in that k numbers

        //according to definition of mex: fi <= fi

        if(k==1)cout<<-1<<'\n';

        else 
        {
            //Max element from range 1
            auto x = max_element(a.begin(),a.begin() + n-k+1) - a.begin();

            // Min element from range 2
            auto y = min_element(a.begin()+n-k+1, a.end()) - a.begin();


            if(a[x] > a[y])
            {
                cout<<x+1<<" "<<y+1<<'\n';
            }
            else cout<<-1<<'\n';
        }
    }
    return 0;
}